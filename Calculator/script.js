const numberbuttons = document.querySelectorAll(".number-button");
const clearbutton = document.querySelector("#clear-button");
const operatorbuttons = document.querySelectorAll(".operator-button");
const equalsbutton = document.querySelector("#equals-button");
const decimalbutton = document.querySelector("#decimal-button");
const signbutton = document.querySelector("#sign-button");
const percentbutton = document.querySelector("#percent-button");
let display = document.querySelector("#display-text");
let smalldisplay = document.querySelector("#small-display-text");

display.textContent = "";
smalldisplay.textContent = "";
let num1;
let num2;
let operator;

numberbuttons.forEach((button) => 
    button.addEventListener("click",() => displayNumber(button.textContent))
);

clearbutton.addEventListener("click",() => clear());

operatorbuttons.forEach(button =>
    button.addEventListener("click", () => {
        num1 = display.textContent;
        operator = button.textContent;
        clear();
        smalldisplay.textContent = num1 + " " + operator + " ";
        
    })
);

equalsbutton.addEventListener("click", () =>
            operate(operator,num1)
);

decimalbutton.addEventListener("click",() => {
    if(!display.textContent.includes(".")){
        display.textContent += ".";
    }
});

signbutton.addEventListener("click", () => {
    let temp = display.textContent
    if(temp[0] === "-"){
        display.textContent = temp.replace("-","");
    }else{
        display.textContent = "-" + temp;
    }
});

percentbutton.addEventListener("click", () =>
    display.textContent = (Number(display.textContent)/100).toString()
);



function displayNumber(num){
    display.textContent += num;
}

function clear(){
    display.textContent = "";
    smalldisplay.textContent = "";
}

function operate(operation,num1,num2){
    num2 = display.textContent;
    smalldisplay.textContent += num2 + " =";
    let num;
    switch(operation){
        case "+":
            num = +num1 + +num2;
            display.textContent = num.toString();
            num1 = display.textContent;
            break;
        case "-":
            num = +num1 - +num2;
            display.textContent = num.toString();
            num1 = display.textContent;
            break;
        case "*":
            num = +num1 * +num2;
            display.textContent = num.toString();
            num1 = display.textContent;
            break;
        case "/":
            if(+num2 === 0){
                display.textContent = NaN;
                break;
            }
            num = +num1 / +num2;
            display.textContent = num.toString();
            num1 = display.textContent;
            break;
    }
    return;
}
