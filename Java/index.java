import java.util.*;
import javax.swing.plaf.synth.Region;
class Student {
    String full_name;
    String student_id;
    String gender;
    String phone_number;
    String department;
    int year;
    String pc_name;
    String pc_serial;
    String pc_model;

    public Student(String full_name, String student_id, String gender, String phone_number, String department, int year,String pc_name,String pc_serial,String pc_model) {
        this.full_name = full_name;
        this.student_id = student_id;
        this.gender = gender;
        this.phone_number = phone_number;
        this.department = department;
        this.year = year;
        this.pc_name = pc_name;
        this.pc_serial = pc_serial;
        this.pc_model = pc_model;
    }

    public void displayDetails() {
        System.out.println("----------------------");
        System.out.println("Student Name: " + full_name);
        System.out.println("Student ID: " + student_id);
        System.out.println("Student Gender: " + gender);
        System.out.println("Student Phone Number: " + phone_number);
        System.out.println("Student Department: " + department);
        System.out.println("Student Year: " + year);
        System.out.println("Student's pc name: " + pc_name);
        System.out.println("Student's Pc serial: " + pc_serial);
        System.out.println("Student's pc model: " + pc_model);
        System.out.println("----------------------");
    }
}

class Staff {
    String full_name;
    String staff_id;
    String gender;
    String phone_number;
    String department;
    String job;
    int year;
    String pc_name;
    String pc_serial;
    String pc_model;

    public Staff(String full_name, String staff_id, String gender, String phone_number, String department, String job, int year,String pc_name,String pc_serial,String pc_model) {
        this.full_name = full_name;
        this.staff_id = staff_id;
        this.gender = gender;
        this.phone_number = phone_number;
        this.department = department;
        this.job = job;
        this.year = year;
        this.pc_name = pc_name;
        this.pc_serial = pc_serial;
        this.pc_model = pc_model;
    }

    public void displayDetails() {
        System.out.println("----------------------");
        System.out.println("Staff's Name: " + full_name);
        System.out.println("Staff's ID: " + staff_id);
        System.out.println("Staff's Gender: " + gender);
        System.out.println("Staff's Phone Number: " + phone_number);
        System.out.println("Staff's Department: " + department);
        System.out.println("Staff's Job: " + job);
        System.out.println("Staff's Year: " + year);
        System.out.println("Staff's pc name: " + pc_name);
        System.out.println("Staff's Pc serial: " + pc_serial);
        System.out.println("Staff's pc model: " + pc_model);
        System.out.println("----------------------");
    }
}

class Nonstaff {
    String full_name;
    String nonstaff_id;
    String gender;
    String phone_number;
    String pc_name;
    String pc_serial;
    String pc_model;

    public Nonstaff(String full_name, String nonstaff_id, String gender, String phone_number,String pc_name,String pc_serial,String pc_model) {
        this.full_name = full_name;
        this.nonstaff_id = nonstaff_id;
        this.gender = gender;
        this.phone_number = phone_number;
        this.pc_name = pc_name;
        this.pc_serial = pc_serial;
        this.pc_model = pc_model;
    }

    public void displayDetails() {
        System.out.println("----------------------");
        System.out.println("NonStaff's Name: " + full_name);
        System.out.println("NonStaff's ID: " + nonstaff_id);
        System.out.println("NonStaff's Gender: " + gender);
        System.out.println("NonStaff's Phone Number: " + phone_number);
        System.out.println("NonStaff's pc name: " + pc_name);
        System.out.println("NonStaff's Pc serial: " + pc_serial);
        System.out.println("NonStaff's pc model: " + pc_model);
        System.out.println("----------------------");
    }
}
class Admin {
    private String username;
    private static String password = "admin";

    public Admin(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public void displayDetails() {
        System.out.println("Admin's Username: " + username);
        System.out.println("Admin's Password: " + password);
    }
    public String getUserName() {
        return username;
    }
    
    public String getPassword() {
        return password;
    }
}
class SuperAdmin {
    private String user_name;
    private static String pass_word = "superadmin";
    

    public SuperAdmin(String user_name, String pass_word) {
        this.user_name = user_name;
        this.pass_word = pass_word;
    }

    public void displayDetails() {
        System.out.println("Admin's Username: " + user_name);
        System.out.println("Admin's Password: " + pass_word);
    }
    public String getUserName() {
        return user_name;
    }
    
    public String getPassword() {
        return pass_word;
    }
}

public class Main {
    static ArrayList<Student> students = new ArrayList<>();
    static ArrayList<Staff> staffs = new ArrayList<>();
    static ArrayList<Nonstaff> nonstaffs = new ArrayList<>();
    static ArrayList<Admin> admins = new ArrayList<>();
    static Scanner input = new Scanner(System.in);
    
    public static void main(String[] args) {
        boolean run = true;
        while (run) {
            System.out.println("PC Registration System");
            System.out.println("-----------------------");
            System.out.println("What do you what to do?");
            System.out.println("1. A super Admin");
            System.out.println("2. An Admin");
            System.out.println("3. Exit");

            System.out.println("Insert your choice");
            int choice = input.nextInt();
            if(choice == 1){
                superAdmin();
            }else if(choice == 2){
                Admin();
            }else if(choice == 3){
                System.out.println("Exiting...... Have a good Day");
                break;
            }else{
                System.out.println("Invalid choice");
            }
        }
    }
    public static void superAdmin() {
        SuperAdmin superAdminInstance = new SuperAdmin("kisu", "superadmin");
        System.out.println("Super Admin");
        System.out.println("-----------");
        System.out.println("Enter your username");
        String username = input.next();
        System.out.println("Enter your password");
        String password = input.next();
        if (username.equals(superAdminInstance.getUserName()) && password.equals(superAdminInstance.getPassword())) {
            System.out.println("Welcome "+ superAdminInstance.getUserName()); 
            while (true) {
                System.out.println("What do you want to do?");
                System.out.println("-----------------------");
                System.out.println("1. Change username and password");
                System.out.println("2. Add Admin");
                System.out.println("3. Remove Admin");
                System.out.println("4. Search Admin");
                System.out.println("5. Display All Admins");
                System.out.println("6. Display All PCs in the System");
                System.out.println("7. Exit");
                System.out.println("-----------------------");

                System.out.println("Insert your choice");
                int choice = input.nextInt();
                if (choice == 1) {
                    changeUsernameAndPassword();
                }else if (choice == 2) {
                    addAdmin();
                } else if (choice == 3) {
                    removeAdmin();
                } else if (choice == 4) {
                    searchAdmin();
                } else if (choice == 5) {
                    displayAdmin();
                } else if (choice == 6) {
                    displaypc();
                } else if (choice == 7) {
                    System.out.println("Exiting...... Have a good Day");
                    break;
                } else {
                    System.out.println("Invalid choice");
                }
            }
        } else {
            System.out.println("Invalid username or password");
        }
        
    }
    public static void changeUsernameAndPassword(){

    }
    public static void addAdmin(){
        System.out.println("Enter admin's username");
        String username = input.next();
        System.out.println("Enter admin's password");
        String password = input.next();
        Admin newAdmin = new Admin(username, password);
        admins.add(newAdmin);
        System.out.println("Admin added successfully");
    }
    public static void removeAdmin(){
        System.out.println("Enter admin's username to remove");
        String username = input.next();
        for (int i = 0; i < admins.size(); i++) {
            if (admins.get(i).getUserName().equals(username)) {
                admins.remove(i);
                System.out.println("Admin removed successfully");
                return;
            }
        }
        System.out.println("Admin not found");
    }
    public static void searchAdmin(){

    }
    public static void displayAdmin(){
        for (int i = 0; i < admins.size(); i++) {
            Admin admin = admins.get(i); 
            admin.displayDetails();
        }
    }
    public static void displaypc(){

    }
    public static void Admin() {
        Admin AdminInstance = new Admin("admin", "admin");
        System.out.println("Admin");
        System.out.println("-----");
        System.out.println("Enter your username");
        String username = input.next();
        System.out.println("Enter your password");
        String password = input.next();
        if (username.equals(AdminInstance.getUserName()) && password.equals(AdminInstance.getPassword())) {
            System.out.println("Welcome "+ AdminInstance.getUserName()); 
            while (true) {
                System.out.println("What do you want to do?");
                System.out.println("-----------------------");
                System.out.println("1. Change username and password");
                System.out.println("2. Register PC for Student");
                System.out.println("3. Register PC for Staff");
                System.out.println("4. Register PC for Nonstaff");
                System.out.println("5. Exit");
                System.out.println("-----------------------");

                System.out.println("Insert your choice");
                int choice = input.nextInt();
                if (choice == 1) {
                    changeUsernameandPassword();
                }else if (choice == 2) {
                    registerPCForStudent();
                } else if (choice == 3) {
                    registerPCForStaff();
                } else if (choice == 4) {
                    registerPCForNonstaff();
                } else if (choice == 5) {
                    System.out.println("Exiting...... Have a good Day");
                    break;
                } else {
                    System.out.println("Invalid choice");
                }
            }
        }else{

        }
    }
    public static void changeUsernameandPassword(){
        System.out.println("Enter new username");
        String newUsername = input.next();
        System.out.println("Enter new password");
        String newPassword = input.next();
        AdminInstance.setUserName(newUsername);
        AdminInstance.setPassword(newPassword);
        System.out.println("Username and password changed successfully");
    }
    public static void registerPCForStudent() {
        while(true){
            System.out.println("Register for PC");
            System.out.println("--------------------");
            System.out.println("What do you want to do?");
            System.out.println("1. Add");
            System.out.println("2. Delete");
            System.out.println("3. search");
            System.out.println("4. Display");
            System.out.println("4. Exit");
            System.out.println("--------------------");
            int choice = input.nextInt();
            switch (choice) {
                case 1:
                    AddPc();
                    break;
                case 2:
                    DeletePc();
                    break;
                case 3:
                    searchPc();
                    break;
                case 4:
                    displayPc();
                    break;
                case 5:
                    System.out.println("Exiting...... Have a good Day");
                    break;             
                default:
                    System.out.println("Invalid choice");
                    break;    
            }        
        }
    }    
        public static void AddPc(){
            System.out.println("Enter student name ");
            String full_name = input.next();
            System.out.println("Enter student ID ");
            String student_id = input.next();
            System.out.println("Enter student Gender ");
            String gender = input.next();
            System.out.println("Enter student Phone Number ");
            String phone_number = input.next();
            System.out.println("Enter student Department ");
            String department = input.next();
            System.out.println("Enter student Year ");
            int year = input.nextInt();
            System.out.println("Enter student's pc name ");
            String pc_name = input.next();
            System.out.println("Enter student's pc serial ");
            String pc_serial = input.next();
            System.out.println("Enter Student's PC Model");
            String pc_model = input.next();

            Student student = new Student(full_name, student_id, gender, phone_number, department, year, pc_name, pc_serial, pc_model);
            students.add(student);
            System.out.println("Student registered successfully");
    }
    public static void DeletePc(){

    }
    public static void searchPc(){

    }
    public static void displayPc(){
        
    }

    public static void registerPCForStaff(){

    }
    public static void registerPCForNonstaff(){

    }
}
