#ifndef CXXT_LABBASE_H
#define CXXT_LABBASE_H

// cxxt headers
#include "common/include/cxxt_common.h"

// standard headers
#include <iostream>

namespace cxxt
{
	// ������������ �������� ������� "run...()" ������� ������������� ���� ������������ ErrorCodes.
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

		// ������ �����.
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
	* ������������
	* =============
	* Lab - ����������� ��� ������������ ����� ��� ������� ��������� ��������� �� ������ ���.
	* ������, ����������� ����� ���� ������� ��� ��������� �����.
	* Pack - ��� ����� ������ �����-�� ����� �����, ��������. � ������ ���������� ����� ������, �����������
	* ����������� ������ ��������������� ������� ��� � ������ ������.
	* Test - ���������� ����.
	* Case - �������� ������ �����, �����-�� ������.
	*/
	class LabBase
	{
	public:
		LabBase() = default;
		virtual ~LabBase() = 0 {}

		// ������ ����� �����������.
		// ������������ �������� ������������� ���� ������������ ErrorCodes.
		virtual int32_t run(uint32_t packIndex, uint32_t testIndex, uint32_t caseIndex) = 0;
	};
} // eof cxxt
#endif // CXXT_LABBASE_H
