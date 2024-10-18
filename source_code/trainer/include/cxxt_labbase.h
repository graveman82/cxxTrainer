#ifndef CXXT_LABBASE_H
#define CXXT_LABBASE_H

// cxxt headers
#include "common/include/cxxt_common.h"

// standard headers
#include <iostream>

namespace cxxt
{
	// Возвращаемое значение методов "run...()" классов соответствует коду перечисления ErrorCodes.
	enum ErrorCodes
	{
		kUnk = -1,
		kOk = 0,
		kTestNotFound,
		kPackNotFound,
		kCaseNotFound,
	};

	class TestBase
	{
	public:
		TestBase(const char* name = nullptr,
			const char* desc = nullptr);

		virtual ~TestBase() = 0;

		// Запуск теста.
		virtual int32_t run();

		std::ostream& printNameAsPrefix();

		const char* getName() const { return m_name ? m_name : "unnamed"; }
		const char* getDesc() const { return m_desc ? m_desc : ""; }

		void setCase(uint32_t caseIndex) { m_iCase = caseIndex; }
	protected:
		virtual int32_t runImpl() = 0;

	private:
		void outputHeader();
		void outputFooter();


		const char* m_name{};
		const char* m_desc{};
		uint32_t m_iCase{};
	};
	/* 
	* =============
	* Терминология
	* =============
	* Lab - лаборатория для определенной книги или большой категории связанных по смыслу тем.
	* Пример, лаборатория может быть создана под обработку книги.
	* Pack - это пакет тестов какой-то главы книги, например. В пакете содержатся много тестов, позволяющих
	* проработать группу взаимосвязанных близких тем с разных сторон.
	* Test - конкретный тест.
	* Case - варианты внутри теста, какие-то случаи.
	*/
	class LabBase
	{
	public:
		LabBase() = default;
		virtual ~LabBase() = 0 {}

		// Запуск теста лаборатории.
		// Возвращаемое значение соответствует коду перечисления ErrorCodes.
		virtual int32_t run(uint32_t packIndex, uint32_t testIndex, uint32_t caseIndex) = 0;
	};
} // eof cxxt
#endif // CXXT_LABBASE_H
