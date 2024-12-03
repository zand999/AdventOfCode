//answer: 332

use std::fs::read_to_string;

fn main() {

    //let mut list1 : Vec<i64> = Vec::new();
    //let mut list2 : Vec<i64> = Vec::new();
    let mut total_good = 0;
    for line in read_to_string("input.txt").unwrap().lines() {
        //result.push(line.to_string());
        let line = line.to_string();
        let mut split = line.split(" ");
        //println!("{l1}");
        
        //let var1 = split.next().unwrap().parse::<i64>().unwrap();
        //let var2 = split.next().unwrap().parse::<i64>().unwrap();

        
        let mut mode = -1;
        //println!("{:?},{:?}",var1,var2);
        let mut previous = split.next().unwrap().parse::<i64>().unwrap();
        let mut current = split.next().unwrap().parse::<i64>().unwrap();

        if previous < current{
            mode = 0;
        
        }else if current < previous{
            mode = 1;
        }

        print!("{previous},");
        print!("{current},");
        for val in split{

            if mode == 0 {
                if previous > current || current - previous > 3 || current - previous < 1 || current == previous{
                    mode = -1;
                    break;
                }
            }else if mode == 1{
                if previous < current || previous - current  < 1 || previous - current  > 3 || current == previous{
                    mode = -1;
                    break;
                }
            }else{
                mode = -1;
                break;
            }

            previous = current;
            current = val.parse::<i64>().unwrap();

            print!("{val},");

            if mode == 0 {
                if previous > current || current - previous > 3 || current - previous < 1 || current == previous{
                    mode = -1;
                    break;
                }
            }else if mode == 1{
                if previous < current || previous - current  < 1 || previous - current  > 3 || current == previous{
                    mode = -1;
                    break;
                }
            }else{
                mode = -1;
                break;
            }
            
        }
        
        if mode > -1 {
            total_good += 1;
            println!("\tSAFE {mode}");
        }else{
            println!("\tUNSAFE");
        }
        
        //list1.push(split.next().unwrap().parse::<i64>().unwrap());
        //list2.push(split.next().unwrap().parse::<i64>().unwrap());

        //break;
    }

    print!("Total good: {total_good}");

    
}