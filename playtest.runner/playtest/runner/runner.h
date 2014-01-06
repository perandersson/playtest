#pragma once
#ifndef _PLAYTEST_RUNNER_H_
#define _PLAYTEST_RUNNER_H_

#include <playtest/playtest.h>

extern int main(int argc, char** argv);

#ifndef PLAYTEST_DEFAULT_CALLBACK
#define PLAYTEST_DEFAULT_CALLBACK playtest::ConsoleOutputCallback
#endif

#endif
