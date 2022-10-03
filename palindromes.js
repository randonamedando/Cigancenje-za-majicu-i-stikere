const palindromes = function (string) {
     string = Array.from(string.toLowerCase());

    const newString = string.filter(char => {
        if(char === " " || char === "." || char === "!" || char === "," || char === "?" || char === "-"){
            return false;
        }
        return true;
    });

    console.log(newString);
    console.log(newString.length);

    for(let i = 0; i < newString.length / 2; i++){
        if(newString[i] != newString[newString.length / 2 - 1 - i]){
            return false;
        }

        return true;
    }

};

