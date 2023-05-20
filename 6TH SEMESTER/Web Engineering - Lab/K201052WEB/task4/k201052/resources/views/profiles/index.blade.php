@extends('profiles.layout')

@section('content')
    <div class="row">
        <div class="col-lg-12 mb-4 mt-5 ">
            <div class="d-flex justify-content-between align-items-center">
                <h2 class="fs-3 mb-0">User Data</h2>

            </div>
        </div>
    </div>

    @if ($message = Session::get('success'))
        <div class="alert alert-success alert-dismissible fade show" role="alert">
            <p class="mb-0">{{ $message }}</p>
            <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
        </div>
    @endif

    <div class="table-responsive">
        <table class="table table-hover table-bordered">
            <thead>
                <tr class="table-dark">
                    <th scope="col">ID</th>
                    <th scope="col">Name</th>
                    <th scope="col">Age</th>
                    <th scope="col">Email</th>
                    <th scope="col">Detail</th>
                    <th scope="col">Image</th>
                    <th scope="col" width="150px">Action</th>
                </tr>
            </thead>
            <tbody>
                @foreach ($profiles as $profile)
                    <tr>
                        <th scope="row">{{ $profile->id }}</th>
                        <td>{{ $profile->name }}</td>
                        <td>{{ $profile->age }}</td>
                        <td>{{ $profile->email }}</td>
                        <td>{{ $profile->detail }}</td>
                        <td>{{ $profile->image }}</td>
                        <td>
                            <form action="" method="POST">
                                <div class="btn-group" role="group">
                                    <a class="btn btn-sm btn-primary"
                                        href="{{ route('profiles.show', $profile->id) }}">Show</a>
                                    @csrf
                                </div>
                            </form>
                        </td>
                    </tr>
                @endforeach
            </tbody>
        </table>
    </div>

    {{-- {!! $profiles->links('pagination::bootstrap-5') !!} --}}
@endsection
