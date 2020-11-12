int pid(int give,int set,int wait,int ftmax)//pid control module
{   
int ft=0;
if (give>set&&ft<ftmax)
{
 
  ft++;
  return ft;
 
  }
else if (set<give&&ft>0)
{
  ft--;
  return ft;
  }
  else
  {
    return ft;
    delay(wait);
    }
}
