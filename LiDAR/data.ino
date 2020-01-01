void Array_sort(int *array , int n){
  int i = 0 , j = 0 , temp = 0;

  for (i = 0 ; i < n ; i++)
  {
    for (j = 0 ; j < n - 1 ; j++)
    {
      if (array[j] > array[j + 1])
      {
        temp        = array[j];
        array[j]    = array[j + 1];
        array[j + 1]  = temp;
      }
    }
  }
}

int Find_median(int array[] , int n){
  int median = 0;

  // if number of elements are even
  if (n % 2 == 0)
    median = (array[(n - 1) / 2] + array[n / 2]) / 2.0;
  // if number of elements are odd
  else
    median = array[n / 2];

  return median;
}
