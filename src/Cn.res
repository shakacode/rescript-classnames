let make = arr => {
  let result = ref("")
  for i in 0 to arr->Array.length - 1 {
    switch arr->Array.getUnsafe(i) {
    | "" => ()
    | name => result := (result.contents == "" ? name : result.contents ++ " " ++ name)
    }
  }
  result.contents
}
