def is_possible(arr, n, m, curr_min):
    students_required = 1
    curr_sum = 0

    for i in range(n):
        if arr[i] > curr_min:
            return False
        
        if curr_sum + arr[i] > curr_min:
            students_required += 1
            curr_sum = arr[i]
            
            if students_required > m:
                return False
        else:
            curr_sum += arr[i]
    
    return True

def find_pages(arr, n, m):
    if n < m:
        return -1

    total_sum = sum(arr)
    max_page = max(arr)

    start = max_page
    end = total_sum
    result = float('inf')

    while start <= end:
        mid = (start + end) // 2

        if is_possible(arr, n, m, mid):
            result = mid
            end = mid - 1
        else:
            start = mid + 1

    return result

if __name__ == "__main__":
    # Input number of books and students
    n = int(input("Enter the number of books: "))
    m = int(input("Enter the number of students: "))

    # Input the number of pages in each book
    print("Enter the number of pages in each book:")
    pages = list(map(int, input().split()))

    # Calculate and output the minimum number of pages
    result = find_pages(pages, n, m)
    print("The minimum number of pages allocated to a student is:", result)
