# Changelog

## [1.0.2] - 2025-06-20

### Fixed
- Fixed mismatch in `library.properties` where version was incorrectly left as `1.0.0` in previous tag `v1.0.1`
- Ensured Arduino Library Manager compatibility with correct metadata version `1.0.2`

### Added
- Added full top-of-file documentation header in `MyDHT22.cpp` and `MyDHT22.h`
- Added line-by-line inline comments in both `.cpp` and `.h` files for better code readability

### Improved
- Cleaned up formatting and whitespace in `MyDHT22.cpp`
- Improved code clarity and developer understanding for future contributions

---

## [1.0.1] - *Skipped* (metadata version mismatch)

###  Not indexed due to version error in `library.properties`.

---

## [1.0.0] - Initial Release

### Added
-  Basic support for reading temperature and humidity from DHT22
-  Manual bit-level protocol implementation (no dependency on `DHT.h`)
-  Functions: `readData()`, `getTemperature()`, `getHumidity()`

---