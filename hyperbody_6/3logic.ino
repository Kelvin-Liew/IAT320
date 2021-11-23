bool sameElements(int Arr1[], int Arr2[], int size) {
    if (size == 0) {
        return true;
    }

    for (int i = size - 1; i >= 0; i--) {
        if (Arr2[i] == Arr1[size-1]) { 
            swapInArray(Arr2, i, (size - 1)); 
            return sameElements(Arr1, Arr2, size - 1); 
        }
    }
    return false;
}

void swapInArray(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void soundCreator(){
  delay(5000);
//  if (sameElements(currCombo,combo1,3)){
//    combo_LRR();
//  }else if (sameElements(currCombo,combo2,3))
//  {      combo_RLL();
//  }else if (sameElements(currCombo,combo3,3))
//  {      combo_LLR();
//  }else if (sameElements(currCombo,combo4,3))
//  {        combo_RRL();
//  }else if (sameElements(currCombo,combo5,3))
//  {        combo_LRL();
//  }else if (sameElements(currCombo,combo6,3))
//  {        combo_RLR();
//  }        
}


void randomizer(){
int ranNum = rand() % 6;
  Serial.print("randomizer playing");   
switch (ranNum)  {
    case 1:
      memcpy(currCombo, combo1, 3); 
  Serial.print("combo1");   

        break;
    case 2:
  memcpy(currCombo, combo2, 3); 
    Serial.print("combo2");   

        break;
    case 3:
  memcpy(currCombo, combo3, 3); 
  Serial.print("combo3");   

        break;
    case 4:
  memcpy(currCombo, combo4, 3); 
  Serial.print("combo4");   

        break;
    case 5:
  memcpy(currCombo, combo5, 3); 
  Serial.print("combo5");   

        break;
    case 6:
  memcpy(currCombo, combo6, 3); 
    Serial.print("combo6");   

        break;
    }
}

void combFinDetection(){

      Serial.println("current punch=" + currentPunch );    
  if(currentPunch>2){

    if(sameElements(performedCombo,currCombo,3)){
  Serial.println(" performed combo is equal to curr combo");     

    randomizer();
    correct();
    delay(2500);
    soundCreator();

    }else{
   //   Serial.print;
      incorrect();
//      soundCreator();

    }
      currentPunch = 0;
      int temp[3] = {0,0,0};
        Serial.println("ccurrent punch is = " + currentPunch);   
//  Serial.print(temp);   

      memcpy(performedCombo,temp,3);
  }
}
