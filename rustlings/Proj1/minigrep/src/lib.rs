use std::error::Error;
use std::{fs,env};

pub struct Config
{   query:String,
    filename:String,
    state:bool
}

impl Config
{   pub fn new(args: &[String])->Result<Config,& 'static str>
    {   if args.len()<3
        {
            return Err("Not enough arguments");
        }

        let query=args[1].clone();
        let filename=args[2].clone();
        let mut state=true;
        if args.len()>=4 
        {   if args[3]=="-i"
            {   
                state = true;
            }
            else if args[3]=="-s"
            {   
                state = false;
            }
            else
            {
                state = !env::var("CASE_INSENSITIVE").is_err();
            }
        }    
        else 
        {
            state = !env::var("CASE_INSENSITIVE").is_err();
        }
        return Ok(Config{query,filename,state});
    }

}

pub fn search<'a>(query: &str,contents:&'a str,state:bool) -> Vec<&'a str>
{
    let mut result=Vec::new();
    for line in contents.lines()
    {   if !state&&line.contains(query)||
            state&&line.to_lowercase().contains(&(query.to_lowercase()))
        {   
            result.push(line);
        }

    }
    return result;
}

pub fn run(config:Config) ->Result<(),Box<dyn Error>>
{   let contents=fs::read_to_string(config.filename)?;
    
    for line in search(&config.query,&contents,config.state)
    {   
        println!("{}",line)
    }
    
    
    return Ok(());
}

#[cfg(test)]
mod tests
{   use super::*;

    #[test]
    fn test1()
    {   let query = "abc";
        let content = "\
aaa
aabcde,def
de";
        assert_eq!(vec!["aabcde,def"],search(query,content,false));
    }

    #[test]
    fn test2()
    {   let query = "Abc";
        let content = "\
aaaBc
aabcde,def
de";
        assert_eq!(vec!["aaaBc","aabcde,def"],search(query,content,true));
    }

}