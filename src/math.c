double mathModulo(double num1, double num2) {
    return (num1 - (num2 * (int)(num1 / num2)));
}

double mathPower(double num1, double num2) {
    double result = 1;

    for(int i = 0; i < num2; i++) {
        result *= num1;
    }

    return result;
}

double solveSimpleEquasion(double num1, char operator ,double num2) {
    if(operator == '+') {
        return num1 + num2;
    } else if(operator == '-') {
        return num1 - num2;
    } else if(operator == '*') {
        return num1 * num2;
    } else if(operator == '/') {
        return num1 / num2;
    } else if(operator == '%') {
        return mathModulo(num1, num2);
    } else if(operator == '^') {
        return mathPower(num1, num2);
    }

    return 0;
}
