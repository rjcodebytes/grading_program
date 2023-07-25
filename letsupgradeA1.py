def calculate_grade(marks):
    if marks >= 90:
        return "A+"
    elif marks >= 80:
        return "A"
    elif marks >= 70:
        return "B"
    elif marks >= 60:
        return "C"
    elif marks >= 50:
        return "D"
    else:
        return "Fail"

def get_valid_marks_input():
    while True:
        try:
            marks = float(input("Enter the marks obtained by the student: "))
            if 0 <= marks <= 100:
                return marks
            else:
                print("Marks should be between 0 and 100. Please try again.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")

def main():
    print("Welcome to the Student Grading Program!")
    while True:
        marks = get_valid_marks_input()
        grade = calculate_grade(marks)
        print(f"Grade: {grade}\n")

        choice = input("Do you want to calculate the grade for another student? (yes/no): ")
        if choice.lower() != "yes":
            print("Exiting the program.")
            break

if __name__ == "__main__":
    main()
