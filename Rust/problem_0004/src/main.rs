use std::io;


fn main() {
    loop {
        println!("Please input your number of digits.");

        let mut num_digts = String::new();

        io::stdin()
            .read_line(&mut num_digts)
            .expect("Failed to read line");

        let num_digts: u32 = match num_digts.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        //let result = mul_3_5_sum(upper_bound);
        //println!("The result is {result}");
        break;
    }
}

