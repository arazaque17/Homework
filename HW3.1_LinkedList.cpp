/*
Course: ECCS 2671 -- Data Structures and Algorithms 1
Group Members
Student 1 = Anthony_Bellino
Student 2 = Yusei_Araki

Use this code template to submit Project 1.

Implement all of the member functions that have not been implemented based on the functionality in the handout

You are NOT allowed to modify the MusicPlayList class, only complete the class implementation.
*/

#include <iostream>
#include <string>

using namespace std;

class MusicPlayList {

private:
	struct SongNode {
		string songName; // name of the song
		int songNum;   // positive int representing the song's order in the playlist
		string songArtist; // musical artist who is associated with the song
		SongNode* next; // forward link
		SongNode* prev; // reverse link
		// SongNode default constructor
		SongNode() { songName = ""; songNum = 1; songArtist = ""; next = prev = nullptr; }
		// SongNode parameterized constructor
		SongNode(string sName, int sNum = 1, string sArtist = "", SongNode* nSong = nullptr, SongNode* pSong = nullptr)
		{
			songNum = sNum; songName = sName; songArtist = sArtist; next = nSong; prev = pSong;
		}
	};

	int numSongs; // number of songs in the playlist 
	SongNode* head; // points to the first song node in the playlist
	SongNode* tail; // points to the last song node in the playlist

	SongNode* getSongNode(const string song);

	SongNode* getSongNode(const int songNumber); // overloaded to search by song number in the list. Returns head if < 2 and tail if >= numSongs or first node pointer whose Songnum >= songNumber

public:
	MusicPlayList() { numSongs = 0; head = tail = nullptr; } // default constructor
	~MusicPlayList(); // destructor 

	void addSong(const string addedSongName);

	void addSong(const string addedSongName, const int songOrder);
	// overload to all adding a song also with the artist name
	void addSong(const string addedSongName, const int songOrder, const string artistName);

	void deleteSong(const string deletedSongName); // deletes a SongNode based on the song name if present
	// overload to also delete a song in the given position in the playlist. Delete first if < 2 or delete last if >= numSongs
	void deleteSong(const int songNumInList);

	void deleteLastSong(); // deletes the last song in the playlist (at the tail)

	int getSongNum(const string searchedSongName); // searches for the song in the playlist and returns the number it is at in the playlist or -1 if not present
	string getSongName(const int songNumInList); // searches for the songNumInList and should return the name of the song; returns first if < 2 or last if >= numSongs, or "Empty Play List" if empty.

	int getNumSongs(); // returns numSongs

	// overload << operator to print the MusicPlayList song names in the order of the playlist
	friend ostream& operator<<(ostream& outputStream, const MusicPlayList& musicList);
};

// Student 1 Member Functions go here
/*
Name: getSongNode
@param: const string song: name of song
@return: SongNode*: Pointer that has the song name or nullptr
*/
MusicPlayList::SongNode* MusicPlayList::getSongNode(const string song)
{
	SongNode* searchNode = head; 
	//searchNode iterates through the list until the end
	while (searchNode != nullptr) {
		// checks for song with matching name
		if (searchNode->songName == song) {
			return searchNode;
		}
		// if not, goes to next node
		searchNode = searchNode->next;

	}
	return nullptr;
}

/*
Name: addSong
@param: addedSongName - name of wanted song
*/
void MusicPlayList::addSong(const string addedSongName)
{
	SongNode* newSong = new SongNode; // creates new song mode
	newSong->songName = addedSongName; // gives name to new song node
	//if list is empty
	if (head == nullptr) {
		head = newSong;
		tail = newSong;
		numSongs++;
		return;
	}

	//if not empty
	newSong->next = head; // sets newsong to front
	head->prev = newSong; // sets old haeder to new node
	head = newSong; // new song is now the head

	SongNode* incrementNode = head->next;
	while (incrementNode != nullptr) //incremnets though list and song
	{
		incrementNode->songNum++;
		incrementNode = incrementNode->next;
	}
	numSongs++;
}

/*
Name: addSong
@param: addedSongName: Name of song, songOrder(where song should go
*/
void MusicPlayList::addSong(const string addedSongName, const int songOrder)
{
	// overloads node to insert new song node at songorder
	SongNode* newSong = new SongNode;
	newSong->songName = addedSongName;
	//when song is placed at head or emtpy list
	if (songOrder < 2 || head == nullptr)
	{
		addSong(addedSongName);
		delete newSong; //deletes node to stop memory leaks
		return;
	}
	//only one song
	
	else if (head->next == nullptr)
	{
		head->next = newSong;
		newSong->prev = head;
		newSong->next = nullptr;
		tail = newSong;
		newSong->songNum = 2; //now there are two songs in the list
		numSongs++;
	}
	//when song is placed at tail
	else if (songOrder > getNumSongs())
	{
		tail->next = newSong;
		newSong->prev = tail;
		newSong->next = nullptr;
		tail = newSong;
		tail->songNum = tail->prev->songNum + 1;
		numSongs++;
		return;
	}
	//Placed in between
	else
	{
		{
			SongNode* location = head; //points to where the song needs to be in the order
			SongNode* prevNode = head; //points to the previous node before the location node

			while (location->songNum != songOrder)// finds where the node needs to be placed
				location = location->next;

			//setting prevNode pointing to the node before where the new song needs to be added
			prevNode = location->prev;

			//setting the new song pointing to the previous node and the next to the node it's replacing
			newSong->prev = prevNode;
			newSong->next = location;

			//setting the nodes before and after new song pointing to the new song
			location->prev = newSong;
			prevNode->next = newSong;

			//sets the new song equal to its new number
			newSong->songNum = songOrder;

			//increments every song after the new song node by one song number
			while (location != nullptr)
			{
				location->songNum++;
				location = location->next;
			}
		}
		numSongs++;
	}
}
/*
name: deleteSong
@param: deletedSongName: name of song
*/
void MusicPlayList::deleteSong(const string deletedSongName)
{
	SongNode* deleteNode = head;
	SongNode* prevNode = head;
	SongNode* nextNode = head;
	
	//if only one song
	if (head == tail)
	{
		tail = nullptr;
		head = nullptr;
		delete deleteNode;
		numSongs--;
	}
	//if song at head
	else if (deleteNode->songName == deletedSongName)
	{
		head = head->next;
		head->prev = nullptr;
		delete deleteNode;
		numSongs--;
	}
	//if in middle or at end
	else
	{
		while (deleteNode->songName != deletedSongName)
		{
			deleteNode = deleteNode->next;
		}
		if (tail->songName == deletedSongName)
		{
			tail = tail->prev;
			tail->next = nullptr;
			delete deleteNode;
			numSongs--;
			return;
		}

		while (prevNode->next != deleteNode) //place the pointer to the node before the node to be deleted
			prevNode = prevNode->next;
		while (nextNode->prev != deleteNode) //place the pointer to the node 
			nextNode = nextNode->next;

		//connects the nodes on both sides of the deleteNode
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete deleteNode; //deletes the requested song

		while (nextNode != nullptr) //corrects the song order 
		{
			nextNode->songNum--;
			nextNode = nextNode->next;
		}
		numSongs--;
	}

}
/*
Name: getSongNum
@param searchedSongName: name of song being searched
@return: returns number of searched song if found if not returns -1*/
int MusicPlayList::getSongNum(const string searchedSongName)
{
	SongNode* incrementNode = head;
	//increments until the node macthes song name is found
	while (incrementNode != nullptr)
	{
		if (incrementNode->songName == searchedSongName)
		{
			return incrementNode->songNum;
		}
		incrementNode = incrementNode->next;
	}
	//returns -1 if song not found
	return -1;
}
// Student 2 Member functions go here

// *******************************************************************
// Destructor to delete all nodes in the Music Play List
// *******************************************************************
MusicPlayList::~MusicPlayList()
{
	SongNode* deleteNode = head;
	SongNode* nextNode = head;
	while (nextNode != nullptr)
	{
		nextNode = nextNode->next;
		delete deleteNode;
		deleteNode = nextNode;
	}
	tail = head = nullptr;
	numSongs = 0;
}

// *******************************************************************
// gets the number of songs in the play list
// *******************************************************************
int MusicPlayList::getNumSongs()
{
	return numSongs;
}

// *******************************************************************
// overloading << operator to print the Music Play List
// outputStream variable is output stream (ostream)
// *******************************************************************
ostream& operator<<(ostream& outputStream, const MusicPlayList& playList)
{
	// SongNode structure is defined inside the MusicPlayList class, we need
	// to use the resolution operator :: to access it.
	// That's why we defined this function as a friend function, so
	// we can access the SongNode struct and all private members.

	MusicPlayList::SongNode* current = playList.head;

	int currentSongNum;
	while (current != nullptr) {
		currentSongNum = current->songNum;
		outputStream << "(" << currentSongNum << ") " << current->songName << ", ";
		current = current->next;
	}
	outputStream << "00" << endl;

	return outputStream;
}

int main()
{
	MusicPlayList list1;
	cout << "We start with: " << list1.getSongName(1) << endl; // Student 2 member function
	list1.addSong("Billie Jean", 3, "Michael Jackson"); // Student 2 member function
	list1.addSong("Ready for It", -1, "Taylor Swift"); // Student 2 member function
	list1.addSong("Gel"); // Student 1 member function
	list1.addSong("Shine", 3); // Student 1 member function
	list1.addSong("Beatin' the Odds", 2); // Student 1 member function
	list1.addSong("Penthouse Pauper", 1, "Molly Hatchet"); // Student 2 member function
	list1.addSong("Can't Touch This", 72); // Student 1 member function

	cout << "The play list has " << list1.getNumSongs() << " songs, including: " << list1 << endl;
	cout << "The song number for Billie Jean is " << list1.getSongNum("Billie Jean") << endl; // Student 1 member function
	cout << "The song in position 2 is " << list1.getSongName(2) << endl; // Student 2 member functions

	list1.deleteLastSong(); // Student 2 member function
	cout << "After deleting the last song: " << list1.getNumSongs() << " songs, including: " << list1 << endl;
	// Student 1 member function
	cout << "The song number for Can't Touch This is now " << list1.getSongNum("Can't Touch This") << " since it's not in the list anymore." << endl;

	list1.deleteSong(-2); // Student 2 member function
	cout << "The play list has " << list1.getNumSongs() << " songs, including: " << list1 << endl;

	list1.deleteSong(80); // Student 2 member function
	cout << "The play list has " << list1.getNumSongs() << " songs, including: " << list1 << endl;

	list1.deleteSong("Shine"); // Student 1 member function
	cout << "The play list has " << list1.getNumSongs() << " songs, including: " << list1 << endl;

	list1.addSong("Back in Black", 10); // Student 1 member function
	list1.deleteSong(2); // Student 2 member function
	cout << "The play list has " << list1.getNumSongs() << " songs, including: " << list1 << endl;

}

