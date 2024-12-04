use std::fs::read_to_string;
//use lazy_static::lazy_static;
//use regex::Regex;
//answer 1831

fn main() {
    let input = read_to_string("input.txt").unwrap();
    //let data = lines.unwrap().chars();
    let mut grid = vec![vec!['#'; 140]; 140];
    //let mut grid = [['#' ; 140] ; 140];
    //println!("{:?}",grid);
    let mut i = 0;
    let mut j = 0;

    for c in input.chars(){

        if c == '\r' || c == '\n'{
            continue;
        }
        if i == 139 && j == 139  {
            break;
        }else{
            grid[j as usize ][(i%140) as usize] = c; 
            println!("{:?}",c);
            i += 1;
        }

        if i % 140 ==0 {
            j += 1;
        }
        //println!("{:?},{:?}",i,j);
    }
    println!("{:?}",grid);

    let mut total = 0;

    
    for i in 1..139{
        for j in 1..139{
            if grid[i][j] == 'A'{
                if grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'M' && grid[i+1][j+1] == 'S' && grid[i+1][j-1] == 'S'{
                    total += 1;
                }else if grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'M' && grid[i+1][j+1] == 'M' && grid[i+1][j-1] == 'S'{
                    total += 1;
                }else if grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'S' && grid[i+1][j+1] == 'M' && grid[i+1][j-1] == 'M'{
                    total += 1;
                }else if grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'S' && grid[i+1][j+1] == 'S' && grid[i+1][j-1] == 'M'{
                    total += 1;
                }
            }
        }
    }

    print!("Total: {:?}",total)


}