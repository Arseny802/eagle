#ifndef FS_MANAGER__H
#define FS_MANAGER__H

#include <iostream>
#include <fstream>
#include <vector>

// Error that occurres when no functionality available
struct FunctionNotReleased : public std::exception {
	const char * what() const throw () {
		return "Dummy class provides no functionality!";
	}
};

// Pointer to any type
typedef void *ANYTYPE;

// one byte length
#define ONE_BYTE 8

// one kilobyte length
#define ONE_KB 1024

// one megabyte length
#define ONE_MB 1048576

// byte to MB or KB to GB
#define CONVERT_DIV 1048576

// convert one GB to bytes
#define GB_TO_BYTES 1073741824

// width of text output
#define WIDTH_INFO_OUTPUT 5

// read file buffer
#define WRITE_FILE__BUFFER_SIZE 20 * ONE_MB

// read file buffer
#define REED_FILE__BUFFER_SIZE ONE_KB 

// Interface of file system management class
class FSManager
{
public:

	// Returns a dynamic string array with file names in current directory
	virtual std::vector<std::string> ListFilesInDirectory(std::string dirName, bool recursively = false) = 0;

	// Creates directory with this name in local directory
	// Returns success.
	virtual bool CreateFolder(std::string dirName) = 0;

	// Delete directory with this name in local directory
	// Returns success.
	virtual bool DeleteFolder(std::string dirName) = 0;

	// Write this data to file with this name.
	// Returns result file size in bytes, 
	// or -1 on open file error,
	// or -2 on write file error.
	virtual long WriteFilePart(std::string filename, ANYTYPE DataBuffer, unsigned int dwBytesToWrite) = 0;

	// Read from file by this filename data to this ReadBuffer this length 
	// of bytes from this position. Returnes ContinuenationPoint (is there more data).
	virtual bool ReadFilePart(std::string filename, ANYTYPE ReadBuffer, unsigned int length, long distanceFrom) = 0;

	// Returns file size in bytes by it's name,
	// or -1 if file doesn't exist,
	// or -2 if couldn't open file.
	virtual long GetFileSize(std::string filename) = 0;

	// Deletes file by it's name. 
	// Returns success.
	virtual bool DeleteFiles(std::string* filenames, unsigned char length = 1) = 0;

	// Rename file by it's name. 
	// Returns success.
	virtual bool RenameFile(std::string oldFilename, std::string newFilename) = 0;
};

#ifdef _WIN32

#include <Windows.h>
#include <tchar.h>

// Windows file managment
class WinFiles : public FSManager
{
public:
	WinFiles();
	~WinFiles();
	virtual std::vector<std::string> ListFilesInDirectory(std::string dirName, bool recursively) {
		throw FunctionNotReleased();
		return std::vector<std::string>();
	}
	virtual bool CreateFolder(std::string dirName) {
		return CreateLocalDirectory(dirName) ? true : false;
	}
	virtual bool DeleteFolder(std::string dirName) {
		return CreateLocalDirectory(dirName) ? true : false;
	}
	virtual long WriteFilePart(std::string filename, ANYTYPE DataBuffer, unsigned int dwBytesToWrite) {
		return WriteToDataFile(filename, DataBuffer, dwBytesToWrite).QuadPart;
	}
	virtual bool ReadFilePart(std::string filename, ANYTYPE ReadBuffer, unsigned int length, long distanceFrom) {
		return ReadDataFile(filename, ReadBuffer, length, distanceFrom) ? true : false;
	}
	virtual long GetFileSize(std::string filename) {
		return GetFileSizeInBytes(filename).QuadPart;
	}
	virtual bool DeleteFiles(std::string* filenames, unsigned char length) {
		return DeleteDataFiles(filenames, length) ? true : false;
	}
	virtual bool RenameFile(std::string oldFilename, std::string newFilename) {
		throw FunctionNotReleased();
		return NULL;
	}
private:
	BOOL CreateLocalDirectory(std::string dirName);
	BOOL DeleteLocalDirectory(std::string dirName);
	LARGE_INTEGER WriteToDataFile(std::string filename, LPVOID DataBuffer, DWORD dwBytesToWrite);
	BOOL ReadDataFile(std::string filename, LPVOID ReadBuffer, DWORD length, uint64_t distanceFrom);
	LARGE_INTEGER GetFileSizeInBytes(std::string filename);
	BOOL DeleteDataFiles(std::string* filenames, unsigned char length);
};

#else
#ifdef _UNIX
#define FS_API_UNIX

// Unix (linux, MAC) file managment
class UnixFiles : public FSManger
{
public:
	UnixFiles();
	~UnixFiles();
	virtual std::vector<std::string> ListFilesInDirectory(std::string dirName, bool recursively) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
	virtual bool CreateFolder(std::string dirName) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
	virtual bool DeleteFolder(std::string dirName) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
	virtual long WriteFilePart(std::string filename, ANYTYPE DataBuffer, unsigned int dwBytesToWrite) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
	virtual bool ReadFilePart(std::string filename, ANYTYPE ReadBuffer, unsigned int length, long distanceFrom) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
	virtual long GetFileSize(std::string filename) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
	virtual bool DeleteFiles(std::string* filenames, unsigned char length) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
	virtual bool RenameFile(std::string oldFilename, std::string newFilename) {
		throw FunctionNotReleased(); //@TODO: create UNIX implemantaion!
		return NULL;
	}
};

#else // no file system detected ?!

// No system managment - no implementation
class DummyClass : public FSManger
{
public:
	DummyClass() {}
	~DummyClass() {}
	virtual std::vector<std::string> ListFilesInDirectory(std::string dirName, bool recursively) {
		throw FunctionNotReleased();
		return NULL;
	}
	virtual bool CreateFolder(std::string dirName) {
		throw FunctionNotReleased();
		return NULL;
	}
	virtual bool DeleteFolder(std::string dirName) {
		throw FunctionNotReleased();
		return NULL;
	}
	virtual long WriteFilePart(std::string filename, ANYTYPE DataBuffer, unsigned int dwBytesToWrite) {
		throw FunctionNotReleased();
		return NULL;
	}
	virtual bool ReadFilePart(std::string filename, ANYTYPE ReadBuffer, unsigned int length, long distanceFrom) {
		throw FunctionNotReleased();
		return NULL;
	}
	virtual long GetFileSize(std::string filename) {
		throw FunctionNotReleased();
		return NULL;
	}
	virtual bool DeleteFiles(std::string* filenames, unsigned char length) {
		throw FunctionNotReleased();
		return NULL;
	}
	virtual bool RenameFile(std::string oldFilename, std::string newFilename) {
		throw FunctionNotReleased();
		return NULL;
	}
};
#endif // _UNIX
#endif // _WIN32

// Static class for file system mangment
// class creating depending on platform.
class FSMangerCreator
{
public:
	// Get file system worker implementation
	static FSManager * GetMangmentSystem()
	{
#ifdef _WIN32
		return new WinFiles();
#else
#ifdef _UNIX
		return new UnixFiles();
#else // no file system detected ?!
		return new DummyClass();
#endif // _UNIX
#endif // _WIN32
	}
private:
	// Do not construct this
	FSMangerCreator();
};

#endif // FS_MANAGER__H