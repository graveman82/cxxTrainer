// standard headers
#include <iostream>

// cxxt headers
#include "common/include/cxxt_common.h"
#include "lab_template/include/cxxt_labtemplate01.h"

int main(int argc, char** argv)
{
	int32_t retVal = cxxt::kOk;
	uint32_t packIndex = 1;
	uint32_t testIndex = 1;
	uint32_t caseIndex = 17;

	cxxt_labtmpl01::Lab lab;
	cxxt::LabBase* pCurrentLab = &lab;

	retVal = pCurrentLab->run(packIndex, testIndex, caseIndex);
	if (retVal == cxxt::kPackNotFound)
	{
		std::cout << "Error. pack(" << packIndex << ") was not found" << std::endl;
	}
	else if (retVal == cxxt::kTestNotFound)
	{
		std::cout << "Error. test(" << testIndex << ") in pack(" << packIndex << ") was not found" << std::endl;
	}
	else if (retVal == cxxt::kCaseNotFound)
	{
		std::cout << "Error. case(" << caseIndex << ") of test(" << testIndex << ") in pack(" << packIndex << ") was not found" << std::endl;
	}
	else if (retVal == cxxt::kTooBigCaseIndex)
	{
		std::cout << "Error. case(" << caseIndex << ") is too big." << std::endl;
	}
	return 0;
}