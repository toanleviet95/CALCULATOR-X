#pragma once

// Cấu trúc cho một số nguyên lớn
// Cấu trúc BigInt này dùng được cho cả số 8 byte và 16 byte, tức là DInt và QInt 
struct BigInt
{
	unsigned int data[4]; // Giới hạn tối đa cho số kiểu BigInt là 16 byte tương ứng với 128 bit
	int EndPos;			  // Vị trí bit cuối cùng tính từ phải qua trái để xác định số bit của BigInt nhập vào
};