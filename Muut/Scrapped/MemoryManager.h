#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <vector>
#include <structs\MemoryTrack.h>

/// Keeps track of memory usage during debugging.
/// Singleton class that is turned off for release.

class MemoryManager
{
public:
	/// Static function that returns instance pointer of MemoryManager.
	///		\return pointer to only instance of this class.
	static MemoryManager* GetInstance();

	/// Deletes MemoryManager instance.
	/// Should be called once application is ready to close.
	static void DeleteInstance();

	/// Pushes MemoryTrack structs to memory vector.
	///		\param track : MemoryTrack information.
	void AddTrack(MemoryTrack track);

	/// Removes MemoryTrack structs from memory vector based on provided pointer.
	///		\param pointer : void* universal pointer.
	void DeleteTrack(void* pointer);

	/// Prints memory leaks to logcat.
	/// Should be called when app is destroyed.
	///		\return true if there are leaks.
	bool WriteLeaks();

	/// Destructor.
	virtual ~MemoryManager() {};

private:
	/// Constructor as private class.
	MemoryManager() {};

	static MemoryManager* instance; ///< Pointer to only instance of the class.
	std::vector<MemoryTrack> memory; ///< Vector keeping track of called new and delete operator.
};

#endif