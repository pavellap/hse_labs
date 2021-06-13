import chalk from "chalk";

function finiteStateMachine(token: string, stateFlag: number): [number | null, boolean] {
    const convertedValue: string = String(stateFlag);

    switch (convertedValue) {
        case "0":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
                stateFlag = 1
                return [stateFlag, false];
            }
            return [null, true];
        case "1":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
                (token >= "0" && token <= "9")) {
                stateFlag = 1;
                return [stateFlag, false];
            }
            if (token === "=") {
                stateFlag = 2;
                return [stateFlag, false];
            } else
                return [null, true]
        case "2":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
                stateFlag = 3;
                return [stateFlag, false];
            }
            if ((token >= "0" && token <= "9")) {
                stateFlag = 4;
                return [stateFlag, false]
            }
            return [null, true];
        case "3":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
                (token >= "0" && token <= "9")) {
                stateFlag = 3;
                return [stateFlag, false];
            }
            if (token === "+" || token === "-") {
                stateFlag = 7;
                return [stateFlag, false];
            }
            return [null, true];
        case "4":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 4;
                return [stateFlag, false]
            }
            if (token === ".") {
                stateFlag = 5;
                return [stateFlag, false]
            }
            return [null, true];
        case "5":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 6;
                return [stateFlag, false]
            }
            return [null, true];
        case "6":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 6;
                return [stateFlag, false]
            }
            if (token === "+" || token === "-") {
                stateFlag = 7;
                return [stateFlag, false];
            }
            return [null, true];
        case "7":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
                stateFlag = 8;
                return [stateFlag, false];
            }
            if ((token >= "0" && token <= "9")) {
                stateFlag = 9;
                return [stateFlag, false]
            }
            return [null, true];
        case "8":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
                (token >= "0" && token <= "9")) {
                stateFlag = 8;
                return [stateFlag, false]
            }
            if (token === "+" || token === "-") {
                stateFlag = 12;
                return [stateFlag, false]
            }
            return [null, true];
        case "9":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 9;
                return [stateFlag, false]
            }
            if (token === ".") {
                stateFlag = 10;
                return [stateFlag, false]
            }
            return [null, true];
        case "10":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 11;
                return [stateFlag, false]
            }
            return [null, true];
        case "11":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 11;
                return [stateFlag, false]
            }
            if (token === "+" || token === "-") {
                stateFlag = 12;
                return [stateFlag, false]
            }
            return [null, true];
        case "12":

            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
                stateFlag = 13;
                return [stateFlag, false]
            }
            if ((token >= "0" && token <= "9")) {
                stateFlag = 14;
                return [stateFlag, false]
            }
            return [null, true];
        case "13":
            if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
                (token >= "0" && token <= "9")) {
                stateFlag = 13;
                return [stateFlag, false]
            }
            if (token === "+" || token === "-") {
                stateFlag = 17;
                return [stateFlag, false]
            }
            return [null, true];
        case "14":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 14;
                return [stateFlag, false]
            }
            if (token === ".") {
                stateFlag = 15;
                return [stateFlag, false]
            }
            return [null, true];
        case "15":
            if ((token >= "0" && token <= "9")) {
                stateFlag = 16;
                return [stateFlag, false]
            }
            return [null, true];
    }
    return [null, true];
}

function check_validity(candidate: string) : void {
    let stateIndicator: number = 0;
    // @ts-ignore
    for (let i of candidate.replace(/ /g,'')) {
        const [state] = finiteStateMachine(i, stateIndicator);
        if (state === null) {
            break;
        }
        stateIndicator = state;
    }
    if (stateIndicator === 13 || stateIndicator === 16)
        console.log(chalk.greenBright(`EXPRESSION: \"${candidate}\" is valid for this language.`));
    else
        console.log(chalk.redBright(`EXPRESSION: \"${candidate}\" is invalid for this language.`))

}

export function main(): void {

    // valid samples
    const firstSample: string = "A = A + 10.3 - B";
    const secondSample: string = "year=10.3+10.5-B";
    const thirdSample: string = "Bomb3 =B+ 90.3 - C";
    const fourthSample: string = "age = variable + 90.3 + 15.3"
    // invalid samples
    const fifthSample: string = "13 = 4.0 + A";
    const sixthSample: string = "var = var * see -13.4";
    const seventhSample: string = "A = var+13.9"

    console.log(chalk.blue("TESTING VALID EXPRESSIONS..."))
    check_validity(firstSample)
    check_validity(secondSample)
    check_validity(thirdSample)
    check_validity(fourthSample)
    console.log(chalk.blue("CHECKING INVALID EXPRESSIONS..."));
    check_validity(fifthSample);
    check_validity(sixthSample);
    check_validity(seventhSample);
}
