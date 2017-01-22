#include<string>
#include<set>
#ifndef MESSAGE_H
#define MESSAGE_H
class Folder;
class Message{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const std::string &str = ""):
		contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void addFold(Folder*);
	void remFold(Folder*);

	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};
class Folder{
	friend class Message;
	friend void swap(Message&, Message&);
public:
	Folder() = default;
	Folder(const Folder&) = default;
	Folder& operator=(Folder&);
	~Folder() = default;
	
	void remMsg(Message*);
	void addMsg(Message*);
	
private:
	std::set<Message*> messages;
};

#endif
