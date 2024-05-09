#pragma once
#include <cstdint>
#include <iostream>
#include <functional>

class Image {
public:
	Image(uint16_t rows, uint16_t columns, std::function<void(uint8_t*)> pixelInitializer)
		: m_rows(rows), m_columns(columns) {
		m_pixels = new uint8_t[m_rows * m_columns];
		pixelInitializer(m_pixels);
	}
	~Image() {
		std::cout << "freeing pixel memory.\n";
		delete[] m_pixels;
	}
	bool imageSizeIsValid() {
		return m_rows <= 1024 && m_columns <= 1024;
	}
	uint16_t pixelIndex(uint16_t x, uint16_t y) {
		return x * m_columns + y;
	}
	// Change the name of this function... Try a more specific name instead of 'get'
	uint8_t getPixel(uint16_t x, uint16_t y) {
		return m_pixels[pixelIndex(x, y)];
	}
	void scanPixels(std::function<void(uint8_t, uint16_t, uint16_t)> takePixel) {
		for (int x = 0; x < m_rows; x++) {
			for (int y = 0; y < m_columns; y++) {
				takePixel(getPixel(x, y), x, y);
			}
		}
	}
	const uint16_t m_rows;
	const uint16_t m_columns;
	uint8_t* m_pixels; // max 1k x 1k image
};
