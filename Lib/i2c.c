#include "i2c.h"

// �� ����������������� ����� AVRmega ����� (�� �� ������) PA4 ��������
// �������� ������ (SDA) � PA5 �������� �������� ������ (SCL).
// ����������� ������� ������ 100 ���, ��� ��������������� �������������
// I2C_Init. �������� ������� I2C ������� �� ������� �������� ������� AVR.
#define F_SCL 100000L   // �������� ������� I2C ����� 100 ���
#define READ 1
#define TW_START 0xA4   // �������� start condition (TWINT,TWSTA,TWEN)
#define TW_STOP 0x94    // �������� stop condition (TWINT,TWSTO,TWEN)
#define TW_ACK 0xC4     // ������� ACK ��� ������������ ���������� (slave)
#define TW_NACK 0x84    // ��� �������� ACK ��� slave
#define TW_SEND 0x84    // �������� ������ (TWINT,TWEN)
#define TW_READY (TWCR & 0x80)      // ����������, ����� TWINT �������� � ���. 1
#define TW_STATUS (TWSR & 0xF8)     // ������ �������� �� �������� �������
#define I2C_Stop() TWCR = TW_STOP   // inline-������ ��� �������� stop condition

void I2C_Init()
// �� ������� 16 MHz ������� SCL ����� ����� 16/(16+2(TWBR)), ���� ������������,
// ��� �������� ������� (�� ����� �������). ����� ��� 100 ��� SCL:
// TWBR = ((F_CPU/F_SCL)-16)/2 = ((16/0.1)-16)/2 = 144/2 = 72
{
   TWSR = 0;            // ��������� ���������
   TWBR = ((F_CPU/F_SCL)-16)/2;  // ��������� ������� SCL
}

byte I2C_Detect(byte addr)
// ������� ���� slave-���������� �� ���������� ������, ������ 1 ����
// ���������� �������, ����� ������ 0.
{
   TWCR = TW_START;           // �������� start condition
   while (!TW_READY);         // �������� ����������
   TWDR = addr;               // �������� ����������
   TWCR = TW_SEND;            //  ������ ����
   while (!TW_READY);         // �������� ����������
   return (TW_STATUS==0x18);  // ������ 1, ���� ���������� �������
}

byte I2C_FindDevice(byte start)
// ������� ��������� ����� ������� ���������� ����������, �������
// � ������ start. ���� ������ �� ������� �� ���� I2C, �� ������ 0.
{
   //����� �� ���� 256 �������:
   for (byte addr=start;addr<0xFF;addr++)
   {
      if (I2C_Detect(addr))
         return addr; // �������, ��� ������ ���-�� �������
   }
   return 0;          // ������ �� �������, ������� 0.
}

void I2C_Start (byte slaveAddr)
{
   I2C_Detect(slaveAddr);
}

byte I2C_Write (byte data)
// ������� �������� ���� ������ slave-����������.
{
   TWDR = data;         // �������� ������
   TWCR = TW_SEND;      //  � �������� ��
   while (!TW_READY);   // �������� ����������
   return (TW_STATUS!=0x28);
}

byte I2C_ReadACK ()
// ������� ��������� ���� ������ �� slave-���������� � ������� ������.
{
   TWCR = TW_ACK;       // ack ��������, ��� ����� 
                        // ����� ��� �������� ������
   while (!TW_READY);   // �������� ����������
   return TWDR;
}

byte I2C_ReadNACK ()
// ������� ��������� ���� ������ �� slave-����������.
{
   TWCR = TW_NACK;      // nack ��������, ��� ����� �������� ������ 1 ����
   while (!TW_READY);   // �������� ����������
   return TWDR;
}

void I2C_WriteByte(byte busAddr, byte data)
// ������������ ���������� ���� � slave-����������.
{
   I2C_Start(busAddr);  // �������� ������ ���� I2C
   I2C_Write(data);     // ����� �������� ����� ������
   I2C_Stop();
}

void I2C_WriteRegister(byte busAddr, byte deviceRegister, byte data)
// ������������ ���������� ���� �� ���������� ������� slave-����������.
{
   I2C_Start(busAddr);        // �������� ������ ���� I2C
   I2C_Write(deviceRegister); // ������ ���� = ����������� ������ ��������
   I2C_Write(data);           // ������ ���� = ������ ��� ����� ��������
   I2C_Stop();
}

byte I2C_ReadRegister(byte busAddr, byte deviceRegister)
// ������� ������ ���� �� ����������� �������� slave-����������.
{
   byte data = 0;
   I2C_Start(busAddr);        // �������� ������ ���� I2C
   I2C_Write(deviceRegister); // ��������� ��������� �� �������
   I2C_Start(busAddr+READ);   // ���������� ��� �������� ������
   data = I2C_ReadNACK();     // ������ ������ ��������
   I2C_Stop();
   return data;
}

