#include <iostream>
#include <jni.h>
#include <fstream>
using namespace std;

vector<string> animalVec; // vector to hold animal information
string trackNumber;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal() // FIXME: add SAVE option
{
	string name, type, subType, eggs, nurse;
	char userChar;

	cout << "Enter animal tracking number: " << endl;
	cin >> trackNumber;

	cout << "Enter animal name: " << endl;
	cin >> name;

	cout << "Enter animal type: " << endl;
	cin >> type;

	cout << "Enter animal sub-type: " << endl;
	cin >> subType;

	cout << "Enter number of eggs: " << endl;
	cin >> eggs;

	cout << "Enter 1 if nursing, 0 if not: " << endl;
	cin >> nurse;

	cout << "Press 's' to save or 'c' to cancel: " << endl;
	cin >> userChar;

	if (userChar == 'c') { // Checks for user input and saves or cancels accordingly
		cout << "Data input cancelled." << endl;
		break;
	}
	else if (userChar == 's') {
		// FIXME: save data
		cout << "Data saved." << endl;
	} else {
		cout << "Invalid choice, terminating..." << endl;
		break;
	}
}


void RemoveAnimal()
{
	char confirm; // Holds user input

	cout << "Enter the track number of the animal you would like to delete: " << endl;
	cin >> trackNumber;
	// FIXME: check if track# is valid

	cout << "Are you sure that you want to delete this animal from the file? Information will be lost forever. (Y / N)" << endl;
	cin >> confirm;

	if (confirm == 'Y' || 'y'){
		// FIXME: delete animal
	}
	else if (confirm == 'N' || 'n'){
		break;
	}else {
		cout << "Invalid choice, terminating..." << endl;
		break;
	}
}

void LoadDataFromFile() // FIXME: save data to vector
{
     ifstream zooData;           // This line and the one below open zoodata.txt file
     zooData.open("zoodata.txt");
}

void SaveDataToFile()
{
	std::ofstream ofs ("zoodata.txt", std::ofstream::trunc); // Overwrites file by opening in truncate mode using fstream
	ofs << // FIXME: get data and save to file
	ofs.close();
	cout << "Save successfully completed" << endl;
}

void DisplayMenu()
{
	int userChoice; // Variable to hold user input for menu

	// Outputs a display menu for user
     cout << "1. Load Animal Data" << endl;
     cout << "2. Generate Data" << endl;
     cout << "3. Display Animal Data" << endl;
     cout << "4. Add Record" << endl;
     cout << "5. Delete Record" << endl;
     cout << "6. Save Animal Data" << endl;

     cin >> userChoice; // Takes in user input for menu choice

     if (userChoice == 1) { // This choice calls Load Animal Data function
    	 LoadDataFromFile();
     }
     else if (userChoice == 2) { // This choice calls the Generate Data function
    	 GenerateData();
     }
     else if (userChoice == 3) { // This choice displays Animal Data
    	 // FIXME: Display data to users
     }
     else if (userChoice == 4) { // This choice calls the Add Animal function
    	 AddAnimal();
     }
     else if (userChoice == 5) { // This choice calls the Remove Animal function
    	 RemoveAnimal();
     }
     else if (userChoice == 6) { // This choice calls the Save Data function
    	 SaveDataToFile();
     } else {                    // Checks for invalid value and re-displays the menu
    	 cout << "Invalid option, please enter a value between 1 - 6" << endl;
    	 DisplayMenu();
     }
}



int main()
{

	GenerateData();
	return 1;
}
