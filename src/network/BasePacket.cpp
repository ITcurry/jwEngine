#include "BasePacket.h"


BasePacket::BasePacket()
{
	// Polymorphism cannot be implemented in constructors
	_fillHead();
}

BasePacket::~BasePacket()
{
}


void BasePacket::zero()
{
	_fillHead();
}

void BasePacket::moveData(BasePacket * packet)
{
	rpos(packet->rpos());
	wpos(packet->wpos());
	_storage = packet->Move();
}

void BasePacket::_fillHead()
{
	rpos(0);
	wpos(0);
	this->_storage.resize(0);
}

int32  BasePacket::getBodySize()
{
	return 0;
}

char * BasePacket::getBodyData()
{
	return NULL;
}

const char * BasePacket::readPointer()
{
	return (const char *)(contents() + _rpos);
}
int32 BasePacket::activeSize()
{
	return _wpos - _rpos;
}

// read msg call
int32  BasePacket::getHeadSize()
{
	return 0;
}

// message head mark length
int32  BasePacket::getMarkLen()
{
	return 0;
}

int BasePacket::getMsgType()
{
	return 0;
}

bool BasePacket::isHeadFull()
{
	return false;
}

// send msg call
int32  BasePacket::sendSize()
{
	return 0;
}

char * BasePacket::sendStream()
{
	return NULL;
}

int BasePacket::readPos()
{
	return rpos();
}

int BasePacket::writePos()
{
	return wpos();
}

//------->get
int8 BasePacket::getInt8() {
	return popValue<int8>();
}
uint8 BasePacket::getUint8() {
	return popValue<uint8>();
}
int16 BasePacket::getInt16() {
	return popValue<int16>();
}
uint16 BasePacket::getUint16() {
	return popValue<uint16>();
}
int32 BasePacket::getInt32() {
	return popValue<int32>();
}
uint32 BasePacket::getUint32() {
	return popValue<uint32>();
}
int64 BasePacket::getInt64() {
	return popValue<int64>();
}
uint64 BasePacket::getUint64() {
	return popValue<uint64>();
}
float BasePacket::getFloat() {
	return popValue<float>();
}
double BasePacket::getDouble() {
	return popValue<double>();
}
std::string BasePacket::getString() {
	return popValue<std::string>();
}


//------->push
void BasePacket::pushInt8(int8 value) {
	*this << value;
}
void BasePacket::pushUint8(uint8 value) {
	*this << value;
}
void BasePacket::pushInt16(int16 value) {
	*this << value;
}
void BasePacket::pushUint16(uint16 value) {
	*this << value;
}
void BasePacket::pushInt32(int32 value) {
	*this << value;
}
void BasePacket::pushUint32(uint32 value) {
	*this << value;
}
void BasePacket::pushInt64(int64 value) {
	*this << value;
}
void BasePacket::pushUint64(uint64 value) {
	*this << value;
}
void BasePacket::pushFloat(float value) {
	*this << value;
}
void BasePacket::pushDouble(double value) {
	*this << value;
}
void BasePacket::pushString(std::string value) {
	*this << value;
}