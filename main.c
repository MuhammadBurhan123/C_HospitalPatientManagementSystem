#include <stdio.h>
#include <stdbool.h>

#define MAX_PATIENTS 30

struct Patient {
    char name[50];
    int id;
    int age;
    char ailment[50];
    bool treatmentStatus;
};

void inputPatientData(struct Patient *patient) {
    printf("Enter patient name: ");
    scanf(" %[^\n]s", patient->name);
    printf("Enter patient ID: ");
    scanf("%d", &patient->id);
    printf("Enter patient age: ");
    scanf("%d", &patient->age);
    printf("Enter patient ailment: ");
    scanf(" %[^\n]s", patient->ailment);
    patient->treatmentStatus = false;
}

void updateTreatmentStatus(struct Patient *patient) {
    patient->treatmentStatus = true;
    printf("Treatment status updated for patient %s (ID: %d).\n", patient->name, patient->id);
}

void displayPatients(struct Patient patients[], int patientCount) {
    printf("Patient Records:\n");
    for (int i = 0; i < patientCount; i++) {
        printf("Name: %s, ID: %d, Age: %d, Ailment: %s, Treatment Status: %s\n",
               patients[i].name,
               patients[i].id,
               patients[i].age,
               patients[i].ailment,
               patients[i].treatmentStatus ? "Completed" : "Pending");
    }
}

int main() {
    struct Patient patients[MAX_PATIENTS];
    int patientCount = 0;

    for (int i = 0; i < MAX_PATIENTS; i++) {
        inputPatientData(&patients[i]);
        patientCount++;

        char choice;
        printf("Do you want to input data for another patient? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    updateTreatmentStatus(&patients[0]);

    displayPatients(patients, patientCount);

    return 0;
}
