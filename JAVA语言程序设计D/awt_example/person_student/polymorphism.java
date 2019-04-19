package person_student;

class Person{ 
  private String name;
  private int age;
  public void setName(String name)
    {	this.name = name;	}
  public String getName()           {	return name;}  
  public void setAge(int age)
     {	this.age = age;	}
  public int getAge(){	return age;	}	
  public String getInfo()
    {	return "Name: " + name + "\tAge: " + age;}
  public  void    setschool(  String  school ){}
}

class Student extends Person
{  private String school;
   public void setSchool(String school){	this.school = school;	}  
   public String getSchool(){	return school;	}
   public String getInfo()
   {return super.getInfo() + "\tSchool: " + school; 	}

}

