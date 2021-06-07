/**
 * I=(I | DF) (+| -) (I | DF) (+| -) (I | DF)
  * I=(I | DF) (+| -) (I | DF) (+| -) (I | DF)
 * I – имя переменной;
 D – целое десятичное число;
 DF – дробное десятичное число
 DZ – десятичное число со знаком
 B – имя процедуры (функции)
 S – строковая константа, т.е. строка, заключенная в кавычки
 _ - пробел (или пустой символ, т.е. на этом месте нет никакой лексемы)
 | - альтернатива (может применяться либо одна, либо другая конструкции)
 [ ] – языковая конструкция может не присутствовать или присутствовать только один раз.
 ( ) – группировка различных операций в выражении, описывающем синтаксис языка
 * */

/**
 * Выражение: var = (int | var)
* 1. Идём по чарам
 * 2. Если попадается предполагаемый чар, то сетим наш флаг в нужное состояние автомата
 * 3. Иначе сетим stateFlag в -1 и возвращаем истину
 * 4. flag = true => автомат в конечном состоянии
 * 5. Начальное состояние - 0
* */


// test example: A = A + 10.3 - B

function finiteStateMachine(token: string, stateFlag: number) : boolean {
    const convertedValue : string = String(stateFlag);
    switch(convertedValue) {
        case "0":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
                stateFlag = 1
                return false;
            }
            return true;
        case "1":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
                (token >= "0" && token <= "9")) {
                stateFlag = 1;
                return false;
            }
            if (token === "=") {
                stateFlag = 2;
                return false;
            }
            else
                return true
        case "2":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
                stateFlag = 3;
                return false;
            }
            if ((token >= "0" && token <= "9")) {
                stateFlag = 4;
                return false
            }
            return true;
        case "3":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
                (token >= "0" && token <= "9")) {
                stateFlag = 3;
                return false;
            }
            if (token === "+" || token === "-") {
                stateFlag = 7;
                return false;
            }
            return true;
        case "4":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 4;
                return false
            }
            if (token === ".") {
                stateFlag = 5;
                return false
            }
            return true;
        case "5":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 6;
                return false
            }
            return true;
        case "6":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 6;
                return false
            }
            if (token === "+" || token === "-") {
                stateFlag = 7;
                return false;
            }
            return true;
        case "7":

    }
}
