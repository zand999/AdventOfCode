use std::fs::read_to_string;
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


        
        println!("{},{:?},{}",denom,values,values.len());

        for i in 0..(2_i64.pow((values.len()-1) as u32)){
            let mut sub_total = values[0];
            for op in 0..values.len()-1{
                if i >> op & 1 == 1{
                    //multiply
                    sub_total *= values[op+1];
                }else{
                    //add
                    sub_total += values[op+1];
                }

            }
            if denom == sub_total{
                total += denom;
                break;
            }
            //total += sub_total;
        }

    }
    println!("Total: {}", total);
}