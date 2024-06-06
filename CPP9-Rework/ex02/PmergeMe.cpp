/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:14:06 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 15:20:29 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(), _deque() {}

PmergeMe::PmergeMe(char **av) : _vector(), _deque() {
    interface(av);
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
    (void)obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) { 
    (void)obj;
    return(*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::print_vector(const std::vector<int> &vector) {
    for (std::vector<int>::size_type i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_deque(const std::deque<int> &deque) {
    for (std::deque<int>::size_type i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
}

bool PmergeMe::isInteger(const std::string& str) {
    if (str.empty())
        return false;
    std::string::const_iterator it = str.begin();
    if (*it == '-' || *it == '+')
        return false;
    while (it != str.end() && std::isdigit(*it))
        ++it;
    return it == str.end();
}

int PmergeMe::check_valid_containers() {
    for (std::vector<int>::size_type i = 0; i < this->_vector.size(); ++i) {
        if (!isInteger(this->_vector[i])) {
            std::cout << "Error" << std::endl;
            return (1);
        }
    }
    return (0);
}

void PmergeMe::fill_containers(char **av) {
    for (size_t i = 1; av[i]; ++i) {
        this->_vector.push_back(av[i]);
        this->_deque.push_back(av[i]);
    }
}

void PmergeMe::insertSortedVector(std::vector<int>& vec, int num) {
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end() && *it < num)
        ++it;
    vec.insert(it, num);
}

void PmergeMe::insertSortedDeque(std::deque<int>& vec, int num) {
    std::deque<int>::iterator it = vec.begin();
    while (it != vec.end() && *it < num)
        ++it;
    vec.insert(it, num);
}

bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            std::cout << "Error" << std::endl;
            return false;
        }
    }
    return true;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    // Get the size of the Vector
    int n = static_cast<int>(arr.size());
    
    // If the deque has 1 or zero elements, it's already sorted
    if (n <= 1)
        return;

    // Step 1: Pairwise comparison and swapping to ensure each pair is in order
    for (int i = 0; i < n - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }

    // Step 2: Iteratively merge subarrays of increasing size
    for (int k = 2; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            int leftsubarray = i; // Start index of the left subarray
            int rightsubarry = std::min(i + k, n); // Start index of the right subarray
            int endleftsubarray = rightsubarry; // End index of the left subarray (start of right subarray)
            int endrightsubarry = std::min(i + 2 * k, n); // End index of the right subarray


            std::vector<int> merged;// Temporary deque to hold merged results

            // Merge the two subarrays
            while (leftsubarray < endleftsubarray && rightsubarry < endrightsubarry) {
                if (arr[leftsubarray] < arr[rightsubarry]) {
                    merged.push_back(arr[leftsubarray++]);
                } else {
                    merged.push_back(arr[rightsubarry++]);
                }
            }

            // Add any remaining elements from the left subarray
            while (leftsubarray < endleftsubarray) {
                merged.push_back(arr[leftsubarray++]);
            }

            // Add any remaining elements from the right subarray
            while (rightsubarry < endrightsubarry) {
                merged.push_back(arr[rightsubarry++]);
            }

            // Copy the merged elements back into the original deque
            std::copy(merged.begin(), merged.end(), arr.begin() + i);
        }
    }
}



void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    // Get the size of the deque
    int n = static_cast<int>(arr.size());

    // If the deque has 1 or zero elements, it's already sorted
    if (n <= 1)
        return;
        
    // Step 1: Pairwise comparison and swapping to ensure each pair is in order
    for (int i = 0; i < n - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }

    // Step 2: Iteratively merge subarrays of increasing size
    for (int k = 2; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            int leftsubarray = i; // Start index of the left subarray
            int rightsubarry = std::min(i + k, n); // Start index of the right subarray
            int endleftsubarray = rightsubarry; // End index of the left subarray (start of right subarray)
            int endrightsubarry = std::min(i + 2 * k, n); // End index of the right subarray

            std::deque<int> merged; // Temporary deque to hold merged results

            // Merge the two subarrays
            while (leftsubarray < endleftsubarray && rightsubarry < endrightsubarry) {
                if (arr[leftsubarray] < arr[rightsubarry]) {
                    merged.push_back(arr[leftsubarray++]);
                } else {
                    merged.push_back(arr[rightsubarry++]);
                }
            }

            // Add any remaining elements from the left subarray
            while (leftsubarray < endleftsubarray) {
                merged.push_back(arr[leftsubarray++]);
            }

            // Add any remaining elements from the right subarray
            while (rightsubarry < endrightsubarry) {
                merged.push_back(arr[rightsubarry++]);
            }

            // Copy the merged elements back into the original deque
            std::copy(merged.begin(), merged.end(), arr.begin() + i);
        }
    }
}

std::vector<int> PmergeMe::convertToIntVector(const std::vector<std::string>& stringVector) {
    std::vector<int> intVector;
    intVector.reserve(stringVector.size());

    for (size_t i = 0; i < stringVector.size(); ++i) {
        std::istringstream iss(stringVector[i]);
        int num;
        if (iss >> num) {
            intVector.push_back(num);
        }
    }
    return intVector;
}

std::deque<int> PmergeMe::convertToIntDeque(const std::deque<std::string>& stringDeque) {
    std::deque<int> intDeque;

    for (size_t i = 0; i < stringDeque.size(); ++i) {
        std::istringstream iss(stringDeque[i]);
        int num;
        if (iss >> num) {
            intDeque.push_back(num);
        }
    }
    return intDeque;
}


void PmergeMe::send_vector() {
    std::vector<int> vector = convertToIntVector(this->_vector);
    std::cout << "Before: ";
    print_vector(vector);
    clock_t start = clock();
    fordJohnsonSortVector(vector);
    clock_t end = clock();
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    size_t size = vector.size();
    std::cout << "After: ";
    print_vector(vector);
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << elapsedTime << " us" << std::endl;
}

void PmergeMe::send_deque() {
    std::deque<int> deque = convertToIntDeque(this->_deque);
    clock_t start = clock();
    fordJohnsonSortDeque(deque);
    clock_t end = clock();
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    size_t size = deque.size();
    std::cout << "Time to process a range of " << size << " elements with std::deque : " << elapsedTime << " us" << std::endl;
}

void PmergeMe::interface(char **av) {
    fill_containers(av);
    if (check_valid_containers())
        return ;
    send_vector();
    send_deque();
}
