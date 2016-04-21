#pragma once

// Cấu trúc cho số thực QFloat 16 byte
struct QFloat
{
	unsigned int data[4]; // Giới hạn tối đa cho số thực kiểu QFloat là 128 bit
	int K = 16383;		  // Số quá K được quy định theo công thức 2^(15 - 1) - 1 do dành 15 bit cho số mũ	
};