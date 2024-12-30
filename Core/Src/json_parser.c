#include "json_parser.h"
#include "main.h"
#include "WeatherGraphics.h"
#include "WeatherGraphics.h"
#include "ili9341.h"
#include "DateAndTime.h"
#include "touch.h"
#include "json_parser.h"
#include "getDataJson.h"
#include"ControlApp.h"

// Định nghĩa các biến toàn cục
uint8_t data1 = '1';
uint8_t data2;
uint16_t idx = 0;
uint8_t a =0;

volatile uint8_t key1_flag = 0;
uint8_t uart_complete = 0; // Cờ báo dữ liệu nhận xong
uint8_t data_ready = 0;

int hour = 0, min = 0;
char date[10] = {0};

char daily_time[MAX_DAYS][11];
char year[MAX_DAYS][5];
char month[MAX_DAYS][3];
char day[MAX_DAYS][3];

float temp_max[MAX_DAYS];
float temp_min[MAX_DAYS];
float wind_max[MAX_DAYS];
float weather_code[MAX_DAYS];
int humidity;
uint8_t RX_buffer[RX_BUFFER_SIZE];






UART_HandleTypeDef huart1;
uint8_t data[] = "U";





static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}



void uartInit()
{
	MX_USART1_UART_Init();
	HAL_UART_Receive_IT(&huart1, &data1, 1);
}















// Định nghĩa các hàm
void extract_value(char *src, const char *key, char *value, int value_size) {
    char *start = strstr(src, key);
    if (start) {
        start += strlen(key) + 2; // Bỏ qua key và ký tự ":
        char *end = strchr(start, ',');
        if (!end) end = strchr(start, '}');
        if (end) {
            int len = end - start;
            if (len >= value_size) len = value_size - 1;
            strncpy(value, start, len);
            value[len] = '\0';
        }
    }
}

void extract_array(char *src, const char *key, char result[][11], int *count) {
    char *start = strstr(src, key);
    if (start) {
        start = strchr(start, '[') + 1; // Tìm '['
        char *end = strchr(start, ']'); // Tìm ']'
        char temp[256];
        int idx = 0;
        while (start < end && idx < *count) {
            char *comma = strchr(start, ',');
            if (comma == NULL || comma > end) comma = end;
            int len = comma - start;
            strncpy(temp, start, len);
            temp[len] = '\0';
            strcpy(result[idx], temp + 1); // Bỏ dấu "
            result[idx][strlen(result[idx]) - 1] = '\0';
            start = comma + 1;
            idx++;
        }
        *count = idx;
    }
}

void extract_float_array(char *src, const char *key, float *result, int *count, char *search_start) {
    char *start = strstr(search_start, key);
    if (start) {
        start = strchr(start, '['); // Tìm '['
        if (!start) return;
        start += 1; // Bỏ qua '['
        char *end = strchr(start, ']'); // Tìm ']'
        if (!end) return;

        char temp[16];
        int idx = 0;

        while (start < end && idx < *count) {
            char *comma = strchr(start, ',');
            if (!comma || comma > end) comma = end;

            int len = comma - start;
            if (len < sizeof(temp)) {
                strncpy(temp, start, len);
                temp[len] = '\0';
                result[idx] = atof(temp); // Chuyển chuỗi thành số thực
                idx++;
            }

            start = comma + 1;
        }
        *count = idx; // Cập nhật số lượng phần tử đã xử lý
    }
}

void get_Temp_Max(char *src, float *result, char *search_start) {
    int count = MAX_DAYS;
    extract_float_array(src, "\"temperature_2m_max\"", result, &count, search_start);
}

void get_Temp_Min(char *src, float *result, char *search_start) {
    int count = MAX_DAYS;
    extract_float_array(src, "\"temperature_2m_min\"", result, &count, search_start);
}

void get_Wind_Speed_Max(char *src, float *result, char *search_start) {
    int count = MAX_DAYS;
    extract_float_array(src, "\"wind_speed_10m_max\"", result, &count, search_start);
}

void get_Weather_Code(char *src, float *result, char *search_start) {
    int count = MAX_DAYS;
    extract_float_array(src, "\"weather_code\"", result, &count, search_start);
}

int get_Humidity(char *src, char *search_start) {
    char value[16];
    extract_value(search_start, "\"relative_humidity_2m\"", value, sizeof(value));
    return atoi(value); // Chuyển chuỗi sang số nguyên
}
void get_Time(void) {
	sscanf(RX_buffer, "Hour:%d, Min:%d, Day:%[^,], DATA_AVAILABLE:%s", &hour, &min, &date, &data_ready);
}
void split_date(const char *date, char *year, char *month, char *day) {
    strncpy(year, date, 4);
    year[4] = '\0';

    strncpy(month, date + 5, 2);
    month[2] = '\0';

    strncpy(day, date + 8, 2);
    day[2] = '\0';
}
char* convertWeatherCode(int code) {
  switch (code) {
    case 0: return "Clear sky";
    case 1: return "Mainly clear";
    case 2: return "Partly cloudy";
    case 3: return "Overcast";
    case 45: return "Fog";
    case 48: return "Depositing rime fog";
    case 51: return "Drizzle: Light";
    case 53: return "Drizzle: Moderate";
    case 55: return "Drizzle: Dense intensity";
    case 56: return "Freezing Drizzle: Light";
    case 57: return "Freezing Drizzle: Dense intensity";
    case 61: return "Rain: Slight";
    case 63: return "Rain: Moderate";
    case 65: return "Rain: Heavy intensity";
    case 66: return "Freezing Rain: Light";
    case 67: return "Freezing Rain: Heavy intensity";
    case 71: return "Snow fall: Slight";
    case 73: return "Snow fall: Moderate";
    case 75: return "Snow fall: Heavy intensity";
    case 80: return "Rain showers: Slight";
    case 81: return "Rain showers: Moderate";
    case 82: return "Rain showers: Violent";
    case 95: return "Thunderstorm: Slight or moderate";
    case 96: return "Thunderstorm with slight hail";
    case 99: return "Thunderstorm with heavy hail";
    default: return "Unknown";
  }
}
void upDateData()
{

    // Vòng lặp tiếp tục nhận dữ liệu cho đến khi hoàn tất
	  data_ready=0;
	  uart_complete = 0;
	  idx = 0;
	  hour = 0; min = 0;
	  data1 = '1';
	  key1_flag = 0;
	  memset(date, 0, sizeof(date));;
	  memset(RX_buffer, 0, sizeof(RX_buffer));
	  HAL_UART_Transmit(&huart1, "U", 1, 1000); // Gửi yêu cầu API


  //  while (data_ready!=1)
    	 while (date[1]==0||uart_complete!=1||HAL_UART_Receive(&huart1, (uint8_t *)&data2, 1, 10) != HAL_OK)
    {

    	if (checkXY(100,295,30,30))
    	 	{
    		break;
    	 	}

    		  if (HAL_UART_Receive(&huart1, (uint8_t *)&data2, 1, 10) == HAL_OK)
    		  {

    			  RX_buffer[idx++] = data2;

    			  if(data2 == '\n')
    			  {
    				  uart_complete = 1;
    				  RX_buffer[idx] = '\0'; // Kết thúc chuỗi
    				  char *data_flag = strstr((char *)RX_buffer, "DATA_AVAILABLE:");
    				  if (data_flag != NULL)
    				  {
    					  int temp = 0;
    					  sscanf(data_flag, "DATA_AVAILABLE:%d", &temp);
    					  data_ready = (uint8_t)temp; // Gán giá trị vào biến data_ready
    				  }
    				  sscanf(RX_buffer, "Hour:%d, Min:%d, Day:%[^,], DATA_AVAILABLE:%s", &hour, &min, &date, &data_ready);
    				  if(data_ready == 1)
    				  {
    					  get_Data_json(); // G�?i hàm xử lý JSON

    			      }

    		    		 if (data_ready == 1 && hour != 0 && min != 0)
    		    		        {
    		    		            break; // Thoát khi đã nhận đủ dữ liệu (ví dụ giờ và phút khác 0)
    		    		        }

    				  //Clear_RX_Buffer(); // Reset buffer sau khi xử lý
    			      idx = 0; // Reset chỉ số buffer
    		          memset(RX_buffer, 0, sizeof(RX_buffer));


    	          }
    			  if (idx >= RX_BUFFER_SIZE - 1)
    			  {
    				  memset(RX_buffer, 0, sizeof(RX_buffer));
    				  idx = 0;
    			  }
    		  }

     }
}



void get_Data_json() {
	char *json_start = strstr((char *)RX_buffer, "{");
	if (!json_start) {
		return; // Không tìm thấy JSON
	}
	char *daily_section = strstr(json_start, "\"daily\":");
	char *current_section = strstr(json_start, "\"current\":");
	sscanf(RX_buffer, "Hour:%d, Min:%d, Day:%[^,],", &hour, &min, &date);
	if (daily_section && current_section) {
		// Gọi các hàm xử lý
		int time_count = MAX_DAYS;
		extract_array(json_start, "\"time\"", daily_time, &time_count);
		for (int i = 0; i < time_count; i++) {
			split_date(daily_time[i], year[i], month[i], day[i]);
		}
		get_Temp_Max(json_start, temp_max, daily_section);
		get_Temp_Min(json_start, temp_min, daily_section);
		get_Wind_Speed_Max(json_start, wind_max, daily_section);
		get_Weather_Code(json_start, weather_code, daily_section);
		humidity = get_Humidity(json_start, current_section);
	}
}
