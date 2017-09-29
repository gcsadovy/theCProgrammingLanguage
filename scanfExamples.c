//suppose we wanted to read the input lines that contain dates of the form

25 Dec 1988;

//the scanf statement is:

int day, year;
char monthname[20];

scanf("%d %s %d", &day, monthname, &year);

//no & is used with monthname because an array name is a pointer

//literal characters can appear in the scanf format string; they must match the same characters in the input; so we could read dates of the form mm/dd/yy with the scanf statement:

scanf("%d/%d/%d", &month, &day, &year);

//scanf ignores blanks and tabs in its format string; furthermore it skips over whitespace as it looks for input values

//to read input whose format is not fixed, it is often best to read a line at a time, then pick it apart with scanf; suppose we wanted to read lines that might contain a date in either of the forms above; then we could write

while (getline(line, sizeof(line)) > 0) {
  if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
    printf("valid: %s\n", line); //25 Dec 1988 form
  else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
    printf("valid: %s\n", line); //mm/dd/yy form
  else
    printf("Invalid: %s\n", line); //invalid form
 }


//calls to scanf can be mixed with calls to other input functions; the next call to any input function will begin bu reading the first character not read by scanf

//a final warning; the arguments to scanf and sscanf must be pointers; by far the most common error is writing:

scanf("%d", n);

//instead of

scanf("%d", &n);

//this error is generally not detected at compile



    
