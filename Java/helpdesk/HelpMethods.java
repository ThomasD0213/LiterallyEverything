import java.util.ArrayList;

public interface HelpMethods
{
    /* 
        TODO:
            put every needed method into this file
    */


    public String getQuestion(int array, int index); //returns a question from specified array and index
    public String getAnswer(int array, int index); //returns a question from specified array and index
    public ArrayList<String> getHardwareQuestions(); //returns hardwareQuestions arraylist
    public ArrayList<String> getHardwareAnswers(); //returns hardwareAnswers arraylist
    public ArrayList<String> getSoftwareQuestions(); //returns softwareQuestions arraylist
    public ArrayList<String> getSoftwareAnswers(); //returns softwareAnswers arraylist
    public ArrayList<String> getTechSuppAnswers(); //returns techSuppAnswers arraylist
    public ArrayList<String> getTechSuppQuestions(); //returns techSuppQuestions arraylist
}