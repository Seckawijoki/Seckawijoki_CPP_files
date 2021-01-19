#include <iostream>
#include <exception>
#include <memory>
using namespace std;

class Image{
	public:
		Image(const string& filename){
			cout<<"Image(): "<<endl;
		}
		~Image(){
			cout<<"~Image(): "<<endl;
		}
};

class AudioClip {
	public:
		AudioClip(const string& filename){
			throw new exception();
			cout<<"AudioClip(): "<<endl;
		}
		~AudioClip(){
			cout<<"~AudioClip(): "<<endl;
		}
};

class BookEntry {
	
	private:
		string name;
		string address;
		Image* const image;
		AudioClip* const audioClip;
		
	public:
		BookEntry(string name, string address, string imageFilename, string audioClipFilename):
			name(name),
			address(address),
			image(initImage(imageFilename)),
			audioClip(initAudioClip(audioClipFilename)){
			cout<<"BookEntry(): 1"<<endl;
		}
		
		Image* initImage(string filename){
			cout<<"initImage(): "<<endl;
			return filename != "" ? new Image(filename) : 0;
		}
		
		AudioClip* initAudioClip(string filename){
			cout<<"initAudioClip(): 1"<<endl;
			try {
				cout<<"initAudioClip(): 2"<<endl;
				return filename != "" ? new AudioClip(filename) : 0;
			} catch (...) {
				cout<<"initAudioClip(): 3"<<endl;
				delete image;
				cout<<"initAudioClip(): 4"<<endl;
				throw;
			}
		}
		
		~BookEntry(){
			release();
		}
		
		void release(){
			cout<<"release(): 1"<<endl;
			delete image;
			cout<<"release(): 2"<<endl;
			delete audioClip;
			cout<<"release(): 3"<<endl;
		}
};



class BookEntry2 {
	
	private:
		string name;
		string address;
		const auto_ptr<Image> image;
		const auto_ptr<AudioClip> audioClip;
		
		
	public:
		BookEntry2(string name, string address, string imageFilename, string audioClipFilename):
			name(name),
			address(address),
			image(imageFilename != "" ? new Image(imageFilename) : 0),
			audioClip(audioClipFilename != "" ? new AudioClip(audioClipFilename) : 0){
			cout<<"BookEntry2(): "<<endl;
		}
		
		~BookEntry2(){
			cout<<"~BookEntry2(): "<<endl;
		}
};

void testPointer(){
	BookEntry* bookEntry = NULL;
	cout<<"testPointer(): 1"<<endl;
	bookEntry = new BookEntry("Seckawijoki", "SZ", "portrait.png", "introduce.wma");
	cout<<"testPointer(): 2"<<endl;
	delete bookEntry;
	cout<<"testPointer(): 3"<<endl;
}

void testPointer2(){
	BookEntry2* bookEntry2 = NULL;
	cout<<"testPointer2(): 1"<<endl;
	try {
		bookEntry2 = new BookEntry2("Seckawijoki", "SZ", "portrait.png", "introduce.wma");
		cout<<"testPointer2(): 2"<<endl;
		delete bookEntry2;
		cout<<"testPointer2(): 3"<<endl;
	} catch (...) {
		cout<<"testPointer2(): 4"<<endl;
		
	}
	cout<<"testPointer2(): 5"<<endl;
}


int main(){
	testPointer2();
//	cout<<"main(): 11"<<endl;
//	BookEntry be("Seckawijoki", "SZ", "portrait.png", "introduce.wma");
//	cout<<"main(): 22"<<endl;
	return 0;
} 
