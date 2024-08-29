#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

class TinyURL {
public:
    TinyURL() : counter(0) {}

    std::string encode(const std::string& longUrl) {
        std::string shortUrl = base62Encode(counter);
        urlMap[shortUrl] = longUrl;
        counter++;
        return "http://tinyurl.com/" + shortUrl;
    }

    std::string decode(const std::string& shortUrl) {
        std::string key = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return urlMap[key];
    }

private:
    std::unordered_map<std::string, std::string> urlMap;
    int counter;
    const std::string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string base62Encode(int value) {
        std::string result;
        while (value > 0) {
            result.push_back(chars[value % 62]);
            value /= 62;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    TinyURL tinyUrlService;
    
    std::string longUrl1 = "https://www.example.com";
    std::string shortUrl1 = tinyUrlService.encode(longUrl1);
    std::cout << "Shortened URL for " << longUrl1 << ": " << shortUrl1 << std::endl;
    
    std::string decodedUrl1 = tinyUrlService.decode(shortUrl1);
    std::cout << "Original URL from " << shortUrl1 << ": " << decodedUrl1 << std::endl;

    return 0;
}
