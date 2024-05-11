#include <iostream>
#include <string>
using namespace std;

int num = 1000;//just for numbering id
const int maxchar = 25;//maximum string length
bool TypeOfUsr;//type of user that access, if not changed it will not login

struct StudentData
{//template to store data
    int IdNum;
    string Name;
    int Age;
    char Gender;
    string Course = "N/a";
    string Address = "N/a";//set default as N/a
    string Status = "N/a";
 
    StudentData* next;
};

void MainTitle() {//title display
    cout << "\n\t\t================================================================\n";
    cout << "\t\t\t\t   Student Management System";
    cout << "\n\t\t================================================================\n";
}

static StudentData* createStudent(string name, int age, char gen, string course) {
    StudentData* newStudent = new StudentData;
    newStudent->Name = name;
    newStudent->IdNum = num;
    newStudent->Age = age;
    newStudent->Gender = gen;
    newStudent->Course = course;


    newStudent->next = nullptr;
    num++;
    return newStudent;
}

static void insertStudent(StudentData*& head, string name, int age, char gen, string course) {
    StudentData* newStudent = createStudent(name, age, gen, course);
    if (head == nullptr) {
        head = newStudent;
    }
    else {
        StudentData* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

static void DisplayStudents(StudentData* head) {//Showing the Student List By 10 

    cout << "\033[2J\033[1;1H";
    MainTitle();
    cout << "\n\t\t\t\t -------- Student List --------\n";
    cout << "\t\tId\tName\t\t\t\tAge\tGender\tCourse\n\n";
    
    if (head == nullptr) {
        cout << "\t\t\tNo students found" << endl;
    }
    else {
        StudentData* temp = head;
        while (temp != nullptr) {
            cout << "\t\t" << temp->IdNum;
            cout << "\t" << temp->Name;
            int namePadding = maxchar - temp->Name.length(); // Calculate padding for name column
            for (int i = 0; i < namePadding; ++i)
                std::cout << " ";
            cout << "\t" << temp->Age;
            cout << "\t" << temp->Gender;
            cout << "\t" << temp->Course<< "\n";
            temp = temp->next;
        }
    }


    cout << "\n\t\t================================================================\n";

    cout << "\t\tEnter Any Key to Return...";
    getchar();
    return;
    
}

void delay(int seconds) {
    int TargetTime = time(0) + seconds;
    while (time(0) < TargetTime) {}
}

static void NewStudent(StudentData*& head) {

    try {

        string name;
        int age;
        char Gender;
        string Course;

        cout << "\033[2J\033[1;1H";
        MainTitle();

        cout << "\n\t\t\tCreating Student";
        for (int i = 0; i < 3; i++) {
            delay(1);
            cout << ".";
        }
        cout << endl << endl;



        while (1) {
            char x;
            cout << "\t\tEnter Name: ";
            cin.ignore();
            getline(cin, name);
            name = name.substr(0, maxchar);
            cout << "\t\tEnter Age: ";
            cin >> age;
            cout << "\t\tEnter Gender: ";
            cin >> Gender;
            cout << "\t\tEnter Course: ";
            cin.ignore();
            getline(cin, Course);
            Course = Course.substr(0, 10);




            cout << "\n\t\tAre You Sure to Add? (Y/N): ";
            cin >> x;
            if (x == 'y' || x == 'Y') {
                insertStudent(head, name, age, Gender, Course);// Insert the new student into the list
                cout << "\t\t";
                for (int i = 0; i < 2; i++) {
                    delay(1);
                }

                cout << "\n\t\tStudent added successfully!\n";
                delay(2);
                return;
            }
            else if (x == 'N' || x == 'n') {
                cout << "\033[2J\033[1;1H";
                MainTitle();
                cout << "\n\t\t\tCreating Student...\n\n";
                continue;
            }
            else if (cin.fail()) {
                //expeption handler
                throw(x);
            }
            else {
                cout << "\n\t\tInvalid Input!!\n";
                delay(1);
            }
        }
    }
    catch (int x) { cout << "\t\t\tExeption CAught"; }
    catch (...) { cout << "\t\t\tExeption Caught!! Invalid Input!!\n";}
}


static void FullDetail(StudentData* temp) {//page for viewing
    cout << "\033[2J\033[1;1H";
    MainTitle();
    cout << "\t\t\t\t----- Personal Data -----\n";
    cout << "\n\t\t\t  NAME     : " << temp->Name;
    cout << "\n\t\t\t  ID       : " << temp->IdNum;
    cout << "\n\t\t\t  AGE      : " << temp->Age;
    cout << "\n\t\t\t  GENDER   : " << temp->Gender;
    cout << "\n\t\t\t  COURSE   : " << temp->Course;

    cout << "\n\t\t\t--------------------------------------------\n";
    cout << "\n\t\t================================================================\n";

    cout << "\t\tEnter Any Key to Return...";
    cin.ignore(); // Clear the newline character from the input buffer
    getchar();
    return;

}

static void Search(StudentData* head) {
    StudentData* temp = head;
    try {
        string target;
        cout << "\033[2J\033[1;1H";
        MainTitle();
        cout << "\t\t\t\t     --- Searching ---\n\n";
        cout << "\t\t\tSearch by Id or Name: ";

        cin.ignore();
        getline(cin, target);

        if (cin.fail()) { throw target; }//Exception if error in input
        cout << "\n\t\t\t\tSearching";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            delay(1);
        }
        cout << endl;

        if (target.empty()) {
            cout << "\t\tEnter Student ID or Name!!\n";
            return; // Exit if empty
        }

        bool searchById = true;//status if the target is int or string

        for (char c : target) {
            if (c < '0' || c > '9') {
                searchById = false; // If any non-digit character is found, set search by name
                break;
            }
        }

        if (searchById) { // Search by ID
            int id = stoi(target); // Convert the string to integer
            
            while (temp != nullptr) {//Traverse until found 
                if (id == temp->IdNum) {
                    FullDetail(temp);// If found Throw pointer add the Full display function Access and display data   
                    return;
                }
                else {
                    temp = temp->next;
                }
            }
        }
        else {//search by name 
            while (temp != nullptr) {
                if (target == temp->Name) {
                    FullDetail(temp);// If found throw pointer add the Full display function will Access and display data
                    return;
                }
                else {
                    temp = temp->next;
                }
            }
        }
        cout << "\n\t\t\t\tNo Match Found!!\n";// all the condition is not met or no record/matched data
        cout << "\n\t\t================================================================\n";
        cout << "\t\tEnter Key to Return...";
        getchar();
        return;
    }
    catch (...) { cout << "\n\n\t\t\tExceptions!! Invalid Data Type!!\n"; }
    
}

static void DeleteMenu(StudentData*& head) {//for deleting Student Node/Data
    StudentData* temp = head;
    StudentData* prev = nullptr;

    cout << "\033[2J\033[1;1H"; // Clear screen

    MainTitle();
    cout << "\n\t\t\t\t----- Delete Student -----\n\n";


    try {
        while (1)
        {

           
            // If head node itself holds the key to be deleted
            int IdTarget;
            cout << "\t\t   Enter Student Id: ";
            cin >> IdTarget;

            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                while (cin.get() != '\n'); // Discard invalid input
                throw IdTarget;
            }

            if (temp != nullptr && temp->IdNum == IdTarget) {
                cout << "\n\t\t\t\t   Student Found!!\n";
                char x;
                cout << "\n\t\t  Are You Sure To Delete? (Y/n): ";
                cin >> x;

                if (x == 'Y' || x == 'y') {
                    cout << "\n\t\t\tDeleting";
                    for (int i = 0; i < 3; ++i) {
                        delay(1);
                        cout << ".";
                    }
                    cout << "\n";
                    head = temp->next; // Changed head
                    delete temp; // Free old head
                    cout << "\n\t\t\tDeleted Successfully!!\n";
                    cout << "\n\t\t================================================================\n";
                    delay(2);
                    return;
                }
                else if (x == 'N' || x == 'n') {

                }
                else { throw x; }
            }

            // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
            while (temp != nullptr && temp->IdNum != IdTarget) {
                prev = temp;
                temp = temp->next;
            }

            
            // If key was not present in the linked list
            if (temp == nullptr) {
                cout << "\n\t\t\tNo Matched ID!!\n";
                cout << "\n\t\t================================================================\n";
                delay(2);
                return;
            }
            
            // Unlink the node from linked list
            prev->next = temp->next;
            delete temp;

        }
        
    }
    catch (...) {
        cout << "\t\t\tException Caught!! Invalid Input!\n";
    }
}

static void Exit() {//Exit Menu

    try {
        while (1) {
            char temp;
            cout << "\n\t\t\tAre You Sure To Exit?(Y/N): ";
            cin >> temp;

            if (temp == 'Y' || temp == 'y') {
                cout << "\033[2J\033[1;1H";
                cout << "\n\t========== Student Management System ==========\n\t";
                cout << "\tThank You For Using Our Program!!\n";
                cout << "\t===============================================\n";
                delay(2);
                
                exit(0);
            }
            else if (temp == 'N' || temp == 'n') { return; }
            else { throw(temp); }
        }
    }
    catch (int temp) {
        cout << "\n\t\t\tExeption Error!! Invalid Input!!\n";
        delay(1);
    }
    
}

static void MenuMain() {//sharable menu for admin and guest
    MainTitle();
    cout << "\n\t\t\t1 --- View Students\n";
    cout << "\t\t\t2 --- New Student\n";
    cout << "\t\t\t3 --- Exit \n";
}

static void EditDataMenu(StudentData*& head) {//belong to admin menu
    try {//admin menu
        while (1) {
            cout << "\033[2J\033[1;1H";
            MainTitle();
            cout << "\n\t\t\t 1 - Add Student\n";
            cout << "\t\t\t 2 - Delete Student\n";
            cout << "\t\t\t 3 - Back\n";

            cout << "\n\t\t\tEnter Choice : ";
            int temp;
            cin >> temp;

            switch (temp)
            {
            case 1:
                NewStudent(head);
                break;
            case 2:
                //delete node
                DeleteMenu(head);
                break;
            case 3:
                return;
            default:
                cout << "\t\tInvalid Input!! Try Again!\n";
                delay(1);
                break;
            }
        }
    }
    catch (...) { cout << "\n\n\nExeption Caught!! Invalid Data Type\n"; }
   
}

class Security {
private:
    static string AdminUname;
    static string AdminPass;
    static string GuestName;
    static string GuestPass;
public:
    

    static string getAName(){
        return AdminUname;
    }
    static string getAPass(){
        return AdminPass;
    }
    static string getGName(){
        return GuestName;
    }
    static string getGPass(){
        return GuestPass;
    }

    static void setAName() {
        cin >> AdminUname;
    }
    static void setAPass() {
        cin >> AdminPass;
    }
    static void setGName() {
        cin >> GuestName;
    }
    static void setGPass() {
        cin >> GuestPass;
    }


    static void SEdit() {
        try {
            int x;
            string temp;
            cout << "\033[2J\033[1;1H";
            MainTitle();
            cout << "\t\t\tEdit Account Security!!\n";
            cout << "\t\t\t1 -- Change Admin UserName\n";
            cout << "\t\t\t2 -- Change Admin Password\n";
            cout << "\t\t\t3 -- Change Guest UserName\n";
            cout << "\t\t\t4 -- Change Guest Password\n";
            cout << "\n\t\t\t\tEnter: ";
            cin >> x;
            cout << "\n\t\t================================================================\n";
            
            switch (x)
            {
            case 1:
                cout << "\t\t\tEnter Changes: ";
                setAName();
                break;
            case 2:
                cout << "\t\t\tEnter Changes: ";
                setAPass();
                break;
            case 3:
                cout << "\t\t\tEnter Changes: ";
                setGName();
                break;
            case 4:
                cout << "\t\t\tEnter Changes: ";
                setGPass();
                break;
            default:
                throw (x);
                break;
            }
            cout << AdminUname << " " << AdminPass;
        } 
        catch (...){}
       
    }

    static void Login() {

        string Usrnm, Passwrd;
        int Count = 3; //allowed retries
        while (Count > 0) {
            cout << "\033[2J\033[1;1H";
            MainTitle();
            cout << "\t\t\t\t\tWelcome!!\n\n";
            cout << "\t\t\t\t--- Log in ---\n";
            cout << "\t\t\tUsername : ";
            cin >> Usrnm;
            cout << "\t\t\tPassword : ";
            cin >> Passwrd;

            if ((Usrnm == getAName() && Passwrd == getAPass()) || (Usrnm == getGName() && Passwrd == getGPass())) {
                cout << "\n\t\t\tLogin Successful!\n";
                cout << "\t\t\t\tWelcome " << Usrnm << "!\n";
                if (Usrnm == getAName()) {
                    TypeOfUsr = true;
                }
                else if (Usrnm == getGName()) {
                    TypeOfUsr = false;
                }
                break;
            }
            else {
                Count--;
                cout << "\n\t\tInvalid Username or Password. Please try again.\n";
                cout << "\t\tAttempts remaining: " << Count << endl;
                if (Count == 0) {
                    cout << "\t\tMaximum login attempts reached. Program terminated.\n";
                    cout << "\n\t\t================================================================\n";
                    delay(2);
                    exit(0);
                }

                cout << "\n\t\t================================================================\n";
                for (int i = 0; i < 3; i++) {
                    cout << "\t\t\t\t.";
                    delay(2);
                }
            }
        }
        cout << "\n\t\t================================================================\n";
        delay(2);
    }
};
//set the default credentials
string Security::AdminUname = "admin";
string Security::AdminPass = "admin";
string Security::GuestName = "guest";
string Security::GuestPass = "guest";

bool SignOut() {//signout confirm prommpt
    char x;
    cout << "\n\t\t\tAre you Sure to Sign Out!! (Y/N) :";
    cin >> x;
    if (x == 'y' || x == 'Y') { // Check if the user confirms signing out
        return true; // Return true if the user confirms
    }
    else {
        return false; // Return false if the user cancels signing out
    }
}

 void MainMenu(StudentData*& head) {
    Security S;
    try {
        while (1) {

            if (TypeOfUsr) {//for autorize admin access
                cout << "\033[2J\033[1;1H";
                MainTitle();
                cout << "\n\t\t\t1 --- View Students\n";
                cout << "\t\t\t2 --- Search Student\n";
                cout << "\t\t\t3 --- Edit Data\n";
                cout << "\t\t\t4 --- Exit \n";
                cout << "\t\t\t5 --- Sign Out\n";
                cout << "\t\t\t6 --- Acc\n\n";

                int temp;
                cout << "\t\t\tEnter Choice: ";
                cin >> temp;

                switch (temp)
                {
                case 1:
                    DisplayStudents(head);// showing the list of students
                    break;
                case 2:
                    Search(head);
                    break;
                case 3:
                    EditDataMenu(head);
                    break;
                case 4:
                    Exit();
                    break;
                case 5:
                    if (SignOut()) {
                         // Return to login screen if the user signs out
                        return;}
                    break;
                case 6:
                    S.SEdit();
                    break;
                default:
                    cout << "\t\t\tInvalid Input!!\n";

                    delay(1);
                    break;
                }
            }
            else if (!TypeOfUsr) {//guest inteference
                int c;
                cout << "\033[2J\033[1;1H";
                MainTitle();
                cout << "\n\t\t\t1 --- View Students\n";
                cout << "\t\t\t2 --- Search Student\n";
                cout << "\t\t\t3 --- Exit \n";
                cout << "\t\t\t4 --- Sign Out\n\n";
                cout << "\t\t\t\tEnter Choice: ";
                try {
                    cin >> c;
                }
                catch (char c) {}
                cout << "\n\t\t================================================================\n";

                switch (c)
                {
                case 1:
                    DisplayStudents(head);
                    // Display students
                    break;
                case 2:
                    Search(head);
                    break;
                case 3:
                    Exit();
                    break;
                case 4:
                    SignOut();
                    return;
                default:
                    cout << "\t\tInvalid choice! Please try again.\n";
                    delay(1);
                    break;
                }
            }
            else { throw (TypeOfUsr); }
                            
        }
                       
    
       

    }
    catch (bool T) {}

}//done

int main() {
    Security SS;
    StudentData* head = nullptr;//Initializing the Head of true List or main list
    insertStudent(head, "Ralph Joedel", 21, 'M', "Bsit");//Add Student In every Program Run
    while (1) {
        Security::Login();
        MainMenu(head);
    }
    return 0;
}
