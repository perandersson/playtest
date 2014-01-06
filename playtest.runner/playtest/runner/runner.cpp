#include <playtest/playtest.h>
#include <memory>

int main(int argc, char** argv)
{
	// Create a console callback.
	std::auto_ptr<playtest::ITestCallback> callback(new playtest::ConsoleOutputCallback());

	// Iterate over all the test suites and evaluate the suites unit-tests.
	const playtest::TestSuiteList& suites = playtest::Repository::Get().GetTestSuites();
	playtest::TestSuiteList::const_iterator it = suites.begin();
	playtest::TestSuiteList::const_iterator end = suites.end();
	for(; it != end; ++it) {
		(*it)->RunUnitTests(callback.get());
	}

	// Check if the callback feels that the test runner should fail
	return callback->Success() ? 0 : -1;
}
