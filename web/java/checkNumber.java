//Написать функцию checkNumber(number), которая определяет: число положительное, отрицательное или ноль; четное оно или нечетное.

package web.java;

public class checkNumber {
    public static void checkNumber(int number) {
        if (number > 0) {
            System.out.println(number + " положительное");
        } else if (number < 0) {
            System.out.println(number + " отрицательное");
        } else {
            System.out.println(number + " ноль");
        }

        if (number % 2 == 0) {
            System.out.println(number + " четное");
        } else {
            System.out.println(number + " нечетное");
        }
    }

    public static void main(String[] args) {
        System.out.print("Введите число: ");
        //Создаем объект Scanner для считывания ввода пользователя
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int number = scanner.nextInt();
        checkNumber(number);
    }
}
