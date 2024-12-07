use std::fs::read_to_string;
//answer: 456565678667482
fn main() {

    //let mut list1 : Vec<i64> = Vec::new();
    //let mut list2 : Vec<i64> = Vec::new();
    let mut total = 0;
    for line in read_to_string("input.txt").unwrap().lines() {
        //result.push(line.to_string());
        
        let line = line.to_string();
        let mut parts = line.split(":");
        
        let mut denom = parts.next().unwrap().parse::<i64>().unwrap();
        let mut str_values = parts.next().unwrap().split(" ");

        let mut values : Vec<i64> = Vec::new();
        
        for val in str_values{
            //print!("'{}'",val);
            if val == ""{
                continue;
            }else{
                values.push(val.parse::<i64>().unwrap());
            }
            
        }


        
        //println!("({},{:?},{})",denom,values,values.len());
        let mut op_table = vec![0; values.len()-1];
        
        for i in 0..(3_i64.pow((values.len()-1) as u32)){
            
            let mut sub_total = values[0];
            //print!("{}",values[0]);

            for op in 0..values.len()-1{
                if op_table[op] == 0{
                    //add
                    //print!("+{}",values[op+1]);
                    sub_total += values[op+1];
                }else if  op_table[op] == 1{
                    //multiply
                    sub_total *= values[op+1];
                    //print!("*{}",values[op+1]);
                } else if op_table[op] == 2 {
                    //sub_total = concat(sub_total as u32,values[op+1] as u32) as i64;
                    //print!("||{}",values[op+1]);
                    sub_total = ((sub_total).to_string() + &(values[op+1].to_string()) ).parse::<i64>().unwrap();
                    //println!("({})",sub_total);
                }

            }
            //println!();
            op_table[0] += 1;
            for op in 0..op_table.len()-1{
                if op_table[op] == 3 {
                    op_table[op+1] += 1;
                    op_table[op] = 0;
                }

            }


            if denom == sub_total{
                //print!("SubTotal: {},", total);
                total += denom;
                break;
            }
            //total += sub_total;
        }
        //println!();

    }

    println!("Total: {}", total);
}

fn concat(a: u32, b: u32) -> u64 {
    a as u64 * 10u64.pow(b.ilog10() + 1) + b as u64
}