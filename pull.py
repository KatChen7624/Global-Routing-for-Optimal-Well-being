import requests

url = "https://air-quality-by-api-ninjas.p.rapidapi.com/v1/airquality"
file = open("cityPM25.txt", 'w')
headers = {
	"content-type": "application/octet-stream",
	"X-RapidAPI-Key": "941ef6e243msh5b31a6423c3e5a5p196048jsn8716bc14f085",
	"X-RapidAPI-Host": "air-quality-by-api-ninjas.p.rapidapi.com"
}
cities = ["San Jose", "San Francisco", "Oakland", "Fremont", "Santa Rosa", "Hayward", "Sunnyvale", "Santa Clara", "Vallejo", "Concord", "Berkeley", "Fairfield", "Richmond", "Antioch", "San Mateo", "Daly City", "Vacaville", "San Leandro", "Livermore", "San Ramon", "Redwood City", "Mountain View", "Milpitas", "Pleasanton", "Napa", "Alameda", "Pittsburg", "Dublin", "Union City", "Walnut Creek", "Palo Alto", "South San Francisco", "Brentwood", "San Rafael", "Cupertino", "Petaluma", "Gilroy", "Novato", "Newark", "Morgan Hill", "Rohnert Park", "Campbell", "San Bruno", "Danville", "Oakley", "Pacifica", "Martinez", "Pleasant Hill", "Foster City", "Menlo Park" ]

for city in cities:
	
	querystring = {"city":city,"state":"CA","country":"US"}
	responses = requests.get(url, headers=headers, params=querystring)
	response = responses.json()

	
	#LOWER IS BETTER
	pm25 = response['PM2.5']

	
	file.write(f"{city}, {pm25['aqi']}\n")


file.close()