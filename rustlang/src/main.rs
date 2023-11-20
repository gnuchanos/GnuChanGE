use std::intrinsics::mir::Len;










fn main() {
    let number1: i16 = 30;
    let number2: i16 = 10;
    let math: i16 = number1 + number2;
    print!("{} + {} = {}\n", number1, number2, math);

    let numx: i16 = 10;
    let borrow = &numx;
    print!("{}\n", borrow);


    


}
