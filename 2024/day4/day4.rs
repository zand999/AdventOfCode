use std::fs::read_to_string;
//use lazy_static::lazy_static;
//use regex::Regex;
//answer: 2336

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

    
    for i in 0..140{
        for j in 0..140{
            //north
            if i > 2{
                if grid[i][j] == 'X' && grid[i-1][j] == 'M' && grid[i-2][j] == 'A' && grid[i-3][j] == 'S' {
                    total += 1;
                }
            }
            //north east
            if i > 2 && j < 137{
                if grid[i][j] == 'X' && grid[i-1][j+1] == 'M' && grid[i-2][j+2] == 'A' && grid[i-3][j+3] == 'S' {
                    total += 1;
                }
            }
            //east
            if j < 137 {
                if grid[i][j] == 'X' && grid[i][j+1] == 'M' && grid[i][j+2] == 'A' && grid[i][j+3] == 'S' {
                    total += 1;
                }
            }
            //south east
            if i < 137 && j < 137 {
                if grid[i][j] == 'X' && grid[i+1][j+1] == 'M' && grid[i+2][j+2] == 'A' && grid[i+3][j+3] == 'S' {
                    total += 1;
                }
            }
            //south
            if  i < 137 {
                if grid[i][j] == 'X' && grid[i+1][j] == 'M' && grid[i+2][j] == 'A' && grid[i+3][j] == 'S' {
                    total += 1;
                }
            }
            //south west
            if i < 137 && j > 2 {
                if grid[i][j] == 'X' && grid[i+1][j-1] == 'M' && grid[i+2][j-2] == 'A' && grid[i+3][j-3] == 'S' {
                    total += 1;
                }
            }
            //west
            if  j > 2 {
                if grid[i][j] == 'X' && grid[i][j-1] == 'M' && grid[i][j-2] == 'A' && grid[i][j-3] == 'S' {
                    total += 1;
                }
            }
            //north west
            if i > 2 && j > 2 {
                if grid[i][j] == 'X' && grid[i-1][j-1] == 'M' && grid[i-2][j-2] == 'A' && grid[i-3][j-3] == 'S' {
                    total += 1;
                }
            }
        }
    }

    print!("Total: {:?}",total)


}