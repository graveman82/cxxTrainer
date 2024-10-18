#ifndef CXXT_LABTEMPLATE01_H
#define CXXT_LABTEMPLATE01_H

// cxxt headers
#include "trainer/include/cxxt_labbase.h"

// standard headers
#include <iostream>

namespace cxxt
{
	namespace labtmpl01
	{
		class Test : public TestBase
		{
		public:
			Test(const char* name = nullptr,
				const char* desc = nullptr)
				: TestBase(name, desc)
			{}

			virtual ~Test() {}

			int32_t runImpl() override
			{
				printNameAsPrefix() << "Hello from lab tmpl 01" << std::endl;
				return kOk;
			}
		};

		class Lab : public LabBase
		{
		public:
			Lab() = default;
			virtual ~Lab() = default;

			int32_t run(uint32_t packIndex, uint32_t testIndex, uint32_t caseIndex) override
			{
				Test test("lab templ 01 hello test", "no details for this test");
				test.setCase(caseIndex);
				return test.run();
			}
		};
	} // eof labtmpl01
} // eof cxxt
#endif // CXXT_LABTEMPLATE01_H
