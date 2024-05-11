#include <iostream>
#include <string>
using namespace std;
int num = 100;
bool TypeOfUsr;//true is admin, false is guest, default is guest
void updateMsg();
void ProgNameDisp();
void delay(int seconds) {
    int TargetTime = time(0) + seconds;
    while (time(0) < TargetTime) {}
}

class StudentData {
private:
    int IdNum;
    string Name;
    int Age;
    char Gender;
    int ContactNum[11];
    string EmailAdd;
    string Status;
    string Address;
    string MedicalInfo;
    string Course;
    string Notes;
public:
    // Constructor
    StudentData(string n, int a, char g, string c, string s = "N/a", string em = "N/a", string add = "N/a", string med = "N/a", string crs = "N/a", string nots = "N/a") :
        Name(n), Age(a), Gender(g), EmailAdd(em), Status(s), Address(add), MedicalInfo(med), Course(crs), Notes(nots) {
        for (int i = 0; i < 11; i++) {
            ContactNum[i] = c[i] - '0';
        }
        IdNum = num;
        num++;
    }
    //setdata
    void setName(string name) {
        Name = name;
    }
    void setAge(int age) {
        Age = age;
    }
    void setgender(char gen) {
        Gender = gen;
    }
    void setContactNum(int cnum[11]) {
        for (int i = 0; i < 11; i++) {
            ContactNum[i] = cnum[i];
        }
    }
    void setEmail(string email) {
        EmailAdd = email;
    }
    void setStatus(string status) {
        Status = status;
    }
    void setAddress(string address) {
        Address = address;
    }
    void setMedicalStatus(string medical) {
        MedicalInfo = medical;
    }
    void setCourse(string cr) {
        Course = cr;
    }
    void setNote(string comment) {
        Notes = comment;
    }
    //getdata====================harang
    int getId()const {
        return IdNum;
    }

    string getName()const {
        return Name;
    }
    int getAge()const {
        return Age;
    }
    char getgender()const {
        return Gender;
    }
    const int* getContactNum()const {
        return ContactNum;
    }
    string getEmail()const {
        return EmailAdd;
    }
    string getStatus()const {
        return Status;
    }
    string getAddress()const {
        return Address;
    }
    string getMedicalStatus()const {
        return MedicalInfo;
    }
    string getCourse()const {
        return Course;
    }
    string getNote()const {
        return Notes;
    }

};
class StudentList {//holder list and manipulation room
private:

    class Node {//structure indirect to student data like holder of memory
    private:
    public:
        StudentData data;
        Node* next;

        Node(StudentData student) : data(student), next(nullptr) {}
    };

    Node* head;
public:
    StudentList() : head(nullptr) {}

    void AddStudent(string n, int a, char g, string c, string s, string em, string add, string med, string crs, string nots) {
        Node* newNode = new Node(StudentData);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void ViewListData() {
        Node* Temp = head;
        Node* prev = nullptr;

        if (Temp == nullptr) {
            cout << "\n\t\t\tThe Student List is Empty!!\n";
            return;
        }
        while (Temp != nullptr) {
            for (int i = 0; i < 9; i++) {
                cout << "\t\t" << i + 1 << ")";
                cout << "\t" << Temp->data.getId() << " ";
                cout << "\t" << Temp->data.getCourse() << " ";
                cout << "\t" << Temp->data.getStatus() << " ";
                cout << "\t" << Temp->data.getName() << " \n";
                prev = Temp;

                if (Temp == nullptr) {
                    cout << "\t\t\tEnd Of the List!!\n";
                    break;
                }
                Temp = Temp->next;
            }
        }
    }
    void DisplayFullData(Node* Temp) {

                cout << "\t\t=== Student Record ===\n";
                cout << "\tID: \t" << Temp->data.getId() << endl;
                cout << "\tName: \t" << Temp->data.getName() << endl;
                cout << "\tGender: \t" << Temp->data.getgender() << endl;
                cout << "\tContact Number: \t" << Temp->data.getContactNum() << endl;
                cout << "\tEmail Address: \t" << Temp->data.getAddress() << endl;
                cout << "\tStatus: \t" << Temp->data.getStatus() << endl;
                cout << "\tAddress: \t" << Temp->data.getAddress() << endl;
                cout << "\tMedical Info: \t" << Temp->data.getMedicalStatus() << endl;
                cout << "\tCourse: \t" << Temp->data.getCourse() << endl;
                cout << "\tRemarks: \t" << Temp->data.getNote() << endl;

            cout << "Press any key to go back...";
            cin.ignore(); // Ignore the newline character from previous input
            getchar(); // Wait for any key press     
            return;
        }
    void Delete_Node(int IdTarget){
    Node* temp = head;
    Node* prev = nullptr;

    // If head node itself holds the key to be deleted
    if (temp != nullptr && temp->data.getId() == IdTarget)
    {
        head = temp->next; // Changed head
        delete temp; // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    while (temp != nullptr && temp->data.getId() == IdTarget)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the linked list
    if (temp == nullptr)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    delete temp;
    }

    void Ename(Node* Temp) {
        cout << "Enter New Name: ";
        string newName;
        cin >> newName;
        Temp->data.setName(newName);
        updateMsg();
    }
    void Eage(Node* Temp) {
        cout << "Enter New Age: ";
        int newAge;
        cin >> newAge;
        Temp->data.setAge(newAge);
        updateMsg();
    }
    void EGender(Node* Temp) {
        cout << "Enter New Gender: ";
        char newGen;
        cin >> newGen;
        Temp->data.setgender(newGen);
        updateMsg();
    }
    void EConNum(Node* Temp) {
        cout << "Enter New Contact Number: ";
        int newNum[11]; // temp
        for (int i = 0; i < 11; ++i) {
            cin >> newNum[i];

        }

        Temp->data.setContactNum(newNum); //set
        updateMsg();
    }
    void EEadd(Node* Temp) {
        cout << "Enter New Email Address: ";
        string tempData;
        cin >> tempData;
        Temp->data.setEmail(tempData);
        updateMsg();
    }
    void EStat(Node* Temp) {
        cout << "Update Status: ";
        string tempData;
        cin >> tempData;
        Temp->data.setStatus(tempData);
        updateMsg();
    }
    void EAdd(Node* Temp) {
        cout << "Enter New Address: ";
        string tempData;
        cin >> tempData;
        Temp->data.setAddress(tempData);
        updateMsg();
    }
    void EMedInfo(Node* Temp) {
        cout << "Enter/Update New Medical Data: ";
        string tempData;
        cin >> tempData;
        Temp->data.setMedicalStatus(tempData);
        updateMsg();
    }
    void ECourse(Node* Temp) {
        cout << "Update Course: ";
        string tempData;
        cin >> tempData;
        Temp->data.setCourse(tempData);
        updateMsg();
    }
    void ENotes(Node* Temp) {
        cout << "Enter New Email Address: ";
        string tempnot;
        cin >> tempnot;
        Temp->data.setNote(tempnot);
        updateMsg();
    }


void EditMenu() {
    Node* Temp = head;//set to search id;
    while (1) {
        int x, id;
        cout << "\033[2J\033[1;1H";
        ProgNameDisp();
        cout << "\n\n\t\t******** Edit/Update the Records ******** \n";
        cout << "\t\t\tEnter Id :";
        cin >> id;

            while (Temp != nullptr) {
                if (id == Temp->data.getId()) {
                    cout << "\t\t\tWhat Do You Want To edit\n\n";
                    cout << "1 - Name\n";
                    cout << "2 - Age\n";
                    cout << "3 - Gender\n";
                    cout << "4 - Contact Number\n";
                    cout << "5 - Email\n";
                    cout << "6 - Status\n";
                    cout << "7 - Address\n";
                    cout << "8 - Medical Info\n";
                    cout << "9 - Course\n";
                    cout << "10 - Notes\n";
                    cout << "11 - Back";
                    cout << "Enter Choice : ";
                    cin >> x;
                    switch (x) {
                    case 1:
                        Ename(Temp);
                        // Edit Student name
                        break;
                    case 2:
                        Eage(Temp);
                        // Edit age
                        break;
                    case 3:
                        EGender(Temp);
                        break;
                    case 4:
                        EConNum(Temp);
                        break;
                    case 5:
                        EEadd(Temp);
                        break;
                    case 6:
                        EStat(Temp);
                        break;
                    case 7:
                        EAdd(Temp);
                        break;
                    case 8:
                        EMedInfo(Temp);
                        break;
                    case 9:
                        ECourse(Temp);
                        break;
                    case 10:
                        ENotes(Temp);
                        break;
                    case 11:
                        return;
                    default:
                        cout << "Invalid choice. Please enter a valid option.\n";
                        break;
                    }
                }
                else { cout << "No Match Id Found!!\n"; }

            }

        }
    }
    void Search(string target){
        Node* temp = head;

        if (target.empty()) {
        cout << "\t\tEnter Student ID or Name!!\n";
        return; // Exit if empty
        }

        bool searchById = true;

        for (char c : target) {
            if (c < '0' || c > '9') {
                searchById = false; // If any non-digit character is found, search by name
                break;
            }
        }

        if (searchById) { // Search by ID
            int id = stoi(target); // Convert the string to integer
            while (temp != nullptr){
                if (id == temp->data.getId()) {
                    DisplayFullData(temp);//show data
                }
                else {
                temp = temp->next;
                }
            }
        }
        else {//search by name
            while (temp != nullptr){
                if (target == temp->data.getName()) {
                    DisplayFullData(temp);//show data
                }
                else {
                temp = temp->next;
                }
            }
        }

        cout << "\t\tNo Match Found!!\n";

    }

    ~StudentList() {//cleaning memory after 
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void ProgNameDisp();
void Search();
void EditDataMenu();
void editMenu();
void ViewStudentsMenu();
void Exit();
void MainMenu();
void Login();
void NewStudent();
bool SignOut();


void ProgNameDisp() {
    cout << "\n\t\t===============================================\n";
    cout << "\t\t\t   Student Management System";
    cout << "\n\t\t===============================================\n";
}

void EditDataMenu() {
    StudentList Sl;
    while (1) {
        cout << "\033[2J\033[1;1H";
        ProgNameDisp();
        cout << "\t\t 1 - Add Student\n";
        cout << "\t\t 2 - Delete Student\n";
        cout << "\t\t 3 - Back\n";

            cout << "\t\tEnter Choice : ";
            int temp;
            cin >> temp;

            switch (temp)
            {
            case 1:
                NewStudent();
                break;
            case 2:
                break;
            case 3:
                return;
            default:
                cout << "\t\tInvalid Input!! Try Again!\n";
                break;
            }
    }
}


void ViewStudentsMenu() {
    StudentList Sl;
    cout << "\033[2J\033[1;1H";
    ProgNameDisp();
    cout << "\t\t\t     === Student List ===\n";
    cout << "\t\tId\tName\t\tSection\t\tStatus\n\n";
    Sl.ViewListData();
    cout << "\n\t\t===============================================\n";

    if (TypeOfUsr){
        //admin
        cout << "\t\t1 - Edit Record\n";
        cout << "\t\t2 - Search\n";
        cout << "\t\t3 - Main Menu\n";

        while (1) {
            cout << "\t\t\tEnter Choice : ";
            int temp;
            cin >> temp;

            switch (temp)
            {
            case 1:
                EditDataMenu();
                return;
            case 2:
                Search();
                break;
            case 3:
                return;
            default:
                cout << "\tInvalid Input!! Try Again!\n";
                break;
            }
        }
    }
    else if (!TypeOfUsr){//guest
        cout << "\t\t1 - Search\n";
        cout << "\t\t2 - Main Menu\n";
        while (1) {
            cout << "\t\t\tEnter Choice : ";
            int temp;
            cin >> temp;

            switch (temp)
            {
            case 1:
                Search();
                break;
            case 2:
                return;
            default:
                cout << "\tInvalid Input!! Try Again!\n";
                break;
            }
        }

    }

   
}

void Exit() {

    for (int i = 0; i < 10; i++) {
        char temp;
        cout << "\tAre You Sure To Exit?(Y/N): ";
        cin >> temp;

        if (temp == 'Y' || temp == 'y') {
            cout << "\033[2J\033[1;1H";
            cout << "\n\t========== Student Management System ==========\n\t";
            cout << "\tThank You For Using Our Program!!\n";
            cout << "\t===============================================\n";
            exit(0);
        }
        else if (temp == 'N' || temp == 'n') { return; }
        else { cout << "Invalid Input!!\n"; }
        if (i == 10) { break; }
    }
}


void MainMenu() {
    try {
            while (1) {
            if (TypeOfUsr){
                cout << "\033[2J\033[1;1H";
                ProgNameDisp();
                cout << "\t\t1 --- View Students\n";
                cout << "\t\t2 --- Edit Data\n";
                cout << "\t\t3 --- Exit \n\n";
                int temp;
                cout << "\t\t\tEnter Choice: ";
                cin >> temp;

                switch (temp)
                {
                case 1:
                    ViewStudentsMenu();
                    break;
                case 2:
                    EditDataMenu();
                    break;
                case 3:
                    Exit();
                    break;
                case 4:
                    if (SignOut()) {
                        return; // Return to login screen if the user signs out
                    }
                    break;
                default:
                    cout << "\t\t\tInvalid Input!!\n";
                    break;
                }
            } 
            else if (!TypeOfUsr) {
                cout << "\033[2J\033[1;1H";
                ProgNameDisp();
                cout << "\t\t1 --- View Students\n";
                cout << "\t\t2 --- Exit \n";
                cout << "\t\t3 --- Sign Out\n\n";

                int temp;
                cout << "\t\t\tEnter Choice: ";
                cin >> temp;

                switch (temp)
                {
                case 1:
                    ViewStudentsMenu();
                    break;
                case 2:
                    Exit();
                    break;
                case 3:
                    if (SignOut()) {
                        return; // Return to login screen if the user signs out
                    }
                    break;
                default:
                    cout << "\t\t\tInvalid Input!!\n";
                    break;
                }
            }else {throw (TypeOfUsr);}
            
        }
    } catch (bool what) {
        cout << "Exeption caught!! Error Credentials";
    }
}//done

void Login() {

    string Usrnm, Passwrd;
    int Count = 3; //allowed retries
    while (Count > 0) {
        cout << "\033[2J\033[1;1H";
        ProgNameDisp();
        cout << "\t\t\t\t   Welcome!!\n\n";
        cout << "\t\t\t\t--- Log in ---\n";
        cout << "\t\tUsername :";
        cin >> Usrnm;
        cout << "\t\tPassword :";
        cin >> Passwrd;

        if ((Usrnm == "admin" && Passwrd == "admin") || (Usrnm == "guest" && Passwrd == "guest")) {
            cout << "\n\t\t\tLogin Successful!\n";
            cout << "\t\t\tWelcome " << Usrnm << "!\n";
            if (Usrnm == "admin") {
                TypeOfUsr = true;
            }
            else if (Usrnm == "guest") {
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
                exit(0);
            }
        }
    }
    cout << "\n\t\t===============================================\n";
    delay(2);
}

void updateMsg() {
    cout << "\n\t\t\t Updating";
    for (int i = 0; i < 10; i++)
    {
        delay(1);
        cout << ".";
    }
}


void NewStudent(){
    ProgNameDisp();
    cout << "\t\t\t\tAdding Student!!\n";

    string name;
    int age;
    char gender;
    string course;

    cout << "\t\tEnter Name: ";
    cin >> name;
    cout << "\t\tEnter Age: ";
    cin >> age;
    cout << "\t\tEnter Gender: ";
    cin >> gender;
    cout << "\t\tEnter Course: ";
    cin >> course;

    StudentData newStudent(name, age, gender, course);
    StudentList SL;
    SL.AddStudent(F StudentData &student);

    cout << "\t\tStudent added successfully!\n";
    delay(2);
}


bool SignOut(){
    char x;
    cout << "Are you Sure to Sign Out!! (Y/N) :";
    cin >> x;
    if (x == 'y' || x == 'Y'){ // Check if the user confirms signing out
        return true; // Return true if the user confirms
    } else {
        return false; // Return false if the user cancels signing out
    }
}

void Search() {
    StudentList SL;
    string target;
    cout << "\t\tSearch by \"Name\" or \"Id\": ";
    cin.ignore(); // Clear the input buffer
    getline(cin, target);

}

int main() {
    StudentData Modi("rJ", 12, 'm', "IT", "N/a");
    StudentList Modify;
    Modify.AddStudent(StudentData("Nmaeaa", 12, 'm', "bsit"));//, "N/a", "email", "Bahay", "med", "bsIT", "Notes");
    Modify.AddStudent(StudentData("Nmaeww", 12, 'm', "IT"));//, "N/a", "email", "Bahay", "med", "IT", "Notes");
    Modify.AddStudent(StudentData("Nmaew", 12, 'm', "IT"));//, "N/a", "email", "Bahay", "med", "IT", "Notes");
    Modify.AddStudent(StudentData("Nmaer", 12, 'm', "IT"));//, "N/a", "email", "Bahay", "med", "IT", "Notes");

    while (1){
        Login();
        MainMenu();
    }

    
}
