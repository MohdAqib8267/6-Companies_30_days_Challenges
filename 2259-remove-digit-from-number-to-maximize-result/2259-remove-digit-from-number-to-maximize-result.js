/**
 * @param {string} number
 * @param {character} digit
 * @return {string}
 */
var removeDigit = function(number, digit) {
    let mx = 0n; // Initialize mx as a BigInt since we'll be comparing BigInt values

    for (let i = 0; i < number.length; i++) {
        if (number[i] == digit) {
            let temp = number.slice(0, i) + number.slice(i + 1);
           let tempBigInt = BigInt(temp);
            mx = mx > tempBigInt ? mx : tempBigInt;
        }
    }

    return mx.toString();
};