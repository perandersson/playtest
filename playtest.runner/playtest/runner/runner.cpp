#include "runner.h"
#include <memory>

int main(int argc, char** argv)
{
	// Create a test callback (default logs everything that happens to the console)
	std::auto_ptr<playtest::ITestCallback> callback(new PLAYTEST_DEFAULT_CALLBACK());

	// Iterate over all the test suites to be executed
	const playtest::TestSuiteList& suites = playtest::Repository::Get().GetTestSuites();
	playtest::TestSuiteList::const_iterator it = suites.begin();
	playtest::TestSuiteList::const_iterator end = suites.end();
	for(; it != end; ++it) {
		(*it)->RunUnitTests(callback.get());
	}

	// Check if the callback feels that the test runner should fail
	return callback->Success() ? 0 : -1;
}
