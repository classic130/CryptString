/*
   ____                          _     ____    _            _
  / ___|  _ __   _   _   _ __   | |_  / ___|  | |_   _ __  (_)  _ __     __ _
 | |     | '__| | | | | | '_ \  | __| \___ \  | __| | '__| | | | '_ \   / _` |
 | |___  | |    | |_| | | |_) | | |_   ___) | | |_  | |    | | | | | | | (_| |
  \____| |_|     \__, | | .__/   \__| |____/   \__| |_|    |_| |_| |_|  \__, |
                 |___/  |_|                                             |___/

  *                          simple implementation of the xor string developed by rijndael
  *
  *                          references:
  *                          https://github.com/JustasMasiulis/xorstr
  *                          https://github.com/qis/xorstr
  * 
  *                          thanks:
  *                          @JustasMasiulis
  *                          @0xd1
 */

#ifndef cryptstring_hpp_
#define cryptstring_hpp_

#ifdef _MSC_VER
#define xor_forceinline __forceinline
#else
#ifdef __GNUC__
#define xor_forceinline __attribute__((always_inline))
#endif
#endif

#define crypt_string(s) ::cryptor::create(s).decrypt()

namespace detail {

    std::uint64_t random_seed(std::uint64_t min, std::uint64_t max) {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<std::uint64_t>(rand() * fraction * (max - min + 1) + min);
    }

    constexpr auto time_const = __TIME__;
    const auto random_key = static_cast<std::uint64_t>(time_const[7]) +
        static_cast<std::uint64_t>(time_const[6]) * ::detail::random_seed(0, 10) +
        static_cast<std::uint64_t>(time_const[4]) * ::detail::random_seed(10, 60) +
        static_cast<std::uint64_t>(time_const[3]) * ::detail::random_seed(60, 600) +
        static_cast<std::uint64_t>(time_const[1]) * ::detail::random_seed(600, 3600) +
        static_cast<std::uint64_t>(time_const[0]) * ::detail::random_seed(3600, 36000);

    template <std::size_t j>
    struct crypt_s {
        xor_forceinline static constexpr void encrypt(char* destination, const char* string,
            std::uint64_t key) {
            destination[j] = string[j] ^ ::detail::random_key;

            ::detail::crypt_s<j - 1>::encrypt(destination, string, ::detail::random_key);
        }
    };

    template <>
    struct crypt_s<0> {
        xor_forceinline static constexpr void encrypt(char* destination, const char* string,
            std::uint64_t key) {
            destination[0] = string[0] ^ ::detail::random_key;
        }
    };
}; // namespace detail

class cryptor {
public:
    template <std::size_t i>
    class string_encryptor {
    public:
        constexpr string_encryptor(const char string[i], std::uint64_t key)
            : buffer_t{},
            decrypted_t{ false },
            key_t{ static_cast<const char>(::detail::random_key % 255) } {
            ::detail::crypt_s<i - 1>::encrypt(buffer_t, string, key_t);
        }

#ifdef __GNUC__
        __attribute__((noinline))
#endif
            const char*
            decrypt() const {
            if (decrypted_t) {
                return buffer_t;
            }

            for (auto& j : buffer_t) {
                j ^= ::detail::random_key;
            }

            decrypted_t = true;

            return buffer_t;
        }

    private:
        mutable char buffer_t[i];
        mutable bool decrypted_t;
        char key_t;
    };

    template <std::size_t s>
    static constexpr auto create(const char(&str)[s]) {
        return string_encryptor<s>{str, s};
    }
};

#endif // end