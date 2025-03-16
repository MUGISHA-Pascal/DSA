#include<iostream>
#include<string>
#include<vector>
struct Patient{
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient* next;
}
struct Doctor{
    int doctor_id;
    string name;
    string specialization;
    Doctor* next;
}
struct Appointment{
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment* next;
}
Patient* patientsHead = nullptr;
Doctor* doctorsHead = nullptr;
Appointment* appointmentsHead = nullptr;
bool patientExists(int id){
    Patient* temp = patientsHead;
    while(temp){
        if(temp->patient_Id == id) return true
        temp = temp->next
    }
    return false
}
bool doctorExists(int id){
    Doctor* temp = doctorsHead;
    while(temp){
        if(temp->doctor_id == id) return true;
    }
    return false;
}

bool appointmentExists(int id){
    Appointment* temp = appointmentsHead;
    while(temp){
        if(temp->appointment_id==id) return true
        temp = temp->next;
    }
    return false;
}
void registerPatient(){
    Patient* newPatient = new Patient;
    cout << "Enter Patient ID : ";
    cin >> newPatient->patient_id;
    if(patientExists(newPatient->patient_id)){
        cout << "Patient ID already exists! \n";
        delete newPatient;
        return;
    }
    cin.ignore();
    cout << "Enter Name : ";
    getline(cin,newPatient->name);
    cout << "Enter Date of Birth : ";
    getline(cin,newPatient->dob);
    cout << "Enter Gender : ";
    getline(cin,newPatient->gender);
    newPatient->next = patientsHeadl
    patientsHead = newPatient;
    cout << "Patient registered successfully!\n";
}
void registerDoctor(){
    Doctor* newDoctor = new Doctor;
    cout << "Enter Doctor ID : ";
    cin >> newDoctor->doctor_id;
    if(doctorExists(newDoctor->doctor_id)){
        cout << "Doctor ID already exists! \n";
        delete newDoctor;
        return;
    }
    cin.ignore();
    cout << "Enter Name : ";
    getline(cin,newDoctor->name);
    cout << "Enter Specialization : ";
    getline(cin,newDoctor->specialization);
    newDoctor->next = doctorsHead;
    doctorsHead = newDoctor;
    cout << "Doctor registered successfully ! \n";
}
void registerAppointment(){
    Appointment* newAppointment = new Appointment;
    cout << "Enter the appointment ID : ";
    cin >> newAppointment->appointment_id;
    if(appointmentExists(newAppointment->appointment_id)){
        cout << "Appointment ID already exists ! \n";
        delete newAppointment;
        return;
    }
    cout << "Enter Patient ID : ";
    cin >> newAppointment->patient_id;
    cout << "Enter Doctor ID : ";
    cin >> newAppointment->doctor_id;
    if(!patientExists(newAppointment->patient_id) || !doctorExists(newAppointment->doctor_id))
}