use std::io;


fn main() {
    loop {
        println!("Please input your number of digits.");

        let mut num_digits = String::new();

        io::stdin()
            .read_line(&mut num_digits)
            .expect("Failed to read line");

        let num_digits: u32 = match num_digits.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        //let result = mul_3_5_sum(upper_bound);
        //println!("The result is {result}");
        //is_palindrome(num_digits);
        break;
    }
}

fn is_palindrome(number: u32) -> bool {
    let num_digits = ((number as f32) + 0.1).log10().ceil() as u32;
    let number_string = number.to_string();
    for i in 0..num_digits {
        if num_digits % 2 == 1 && i == (num_digits  - 1)/ 2 {
            return true;
        }
        if number_string[i as usize] != number_string[num_digits as usize - i as usize- (1 as usize)] {
            return false;
        }
    }
    true 
}

