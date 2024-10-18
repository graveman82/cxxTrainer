#ifndef CXXT_LABTEMPLATE01_H
#define CXXT_LABTEMPLATE01_H

// cxxt headers
#include "trainer/include/cxxt_labbase.h"

// standard headers
#include <iostream>

namespace cxxt_labtmpl01
{
	class Lab : public cxxt::LabBase
	{
	public:
		Lab() = default;
		virtual ~Lab() = default;

		int32_t run(uint32_t packIndex, uint32_t testIndex, uint32_t caseIndex) override;
	};
		

} // eof cxxt_labtmpl01
#endif // CXXT_LABTEMPLATE01_H
