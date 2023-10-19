// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    MemLen = (len + sizeof(TELEM) - 1) / (8 * sizeof(TELEM));

    pMem = new TELEM[MemLen];
    
    BitLen = len;
    
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;

    pMem = new TELEM[MemLen];

    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}
TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return FAKE_INT;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return FAKE_INT;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Index out of range");  // Throw an exception for out-of-range index
    } else {
        int memIndex = GetMemIndex(n);  // Calculate the index in pMem
        TELEM memMask = GetMemMask(n);  // Calculate the bit mask
        pMem[memIndex] |= memMask;      // Set the bit to 1
    }
}

void TBitField::ClrBit(const int n) // очистить бит
{
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Index out of range");  // Throw an exception for out-of-range index
    } else {
        int memIndex = GetMemIndex(n);  // Calculate the index in pMem
        TELEM memMask = GetMemMask(n);  // Calculate the bit mask
        return (pMem[memIndex] & memMask) != 0;  // Return 1 if the bit is set, 0 if it's clear
    }
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
     
if (this == &bf) {
        return *this;  // Check for self-assignment
    }

    // Deallocate the current memory
    delete[] pMem;

    // Copy the BitLen and MemLen from the source bit field 'bf'
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;

    // Allocate new memory for pMem
    pMem = new TELEM[MemLen];

    // Copy the contents of 'bf.pMem' into the new 'pMem'
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }

    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    (BitLen != bf.BitLen) {
        return 0;  // Bit fields have different lengths, not equal
    }

    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 0;  // Mismatch found, bit fields are not equal
        }
    }

    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator~(void) // отрицание
{
    return FAKE_BITFIELD;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    return ostr;
}
