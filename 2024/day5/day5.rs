use std::fs::read_to_string;

fn main() {

    let mut input_section = true;
    let mut list1 : Vec<i64> = Vec::new();
    let mut list2 : Vec<i64> = Vec::new();

    let mut total = 0;
    for line in read_to_string("input.txt").unwrap().lines() {
        //result.push(line.to_string());
        let line = line.to_string();
        //let mut split = line.split("|");
        //let mut split = line.split(",");
        if input_section{
            if line == ""{
                input_section = false;
                continue
            }

            let mut split = line.split("|");

            list1.push(split.next().unwrap().parse::<i64>().unwrap());
            list2.push(split.next().unwrap().parse::<i64>().unwrap());
            
        }else{
            let mut page_order : Vec<i64> = Vec::new();
            let mut split = line.split(",");

            for num in split{
                page_order.push(num.parse::<i64>().unwrap());
            }
            let mut good = true;
            //run though list of pages
            for page in 0..(page_order.len()-1){
                
                for page_index_to_be_before in 0..list2.len(){

                    if page_order[page] == list2[page_index_to_be_before]{
                        for next_page in page+1..(page_order.len()){
                            if(page_order[next_page] == list1[page_index_to_be_before]){
                                good = false;
                                print!("Rule: {:?},{:?},{:?} ",page_index_to_be_before, list1[page_index_to_be_before], list2[page_index_to_be_before]);
                                break;
                            }
                        }
                    }
                    if !good {break;}
                }
                if !good {break;}

            }
            print!("{:?}",page_order);
            if good {
                total += page_order[page_order.len() / 2];
                println!("\t Good");

            }else{
                println!("\t Bad");

            }
            
        }
        
        
        
        


    }
    println!("Total: {total}");

}